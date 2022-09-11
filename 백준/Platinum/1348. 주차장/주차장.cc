#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define N 50
#define INF 987654321

using namespace std;

int r, c;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

char input[N + 1][N + 1];
int visited[N + 1][N + 1], dist[101][101];
vector<pair<int, int>> car;
vector<pair<int, int>> park;

vector<int> g[101];
int match[101];
bool v[101];

void bfs(int cur)
{
	memset(visited, -1, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ car[cur].first, car[cur].second });
	visited[car[cur].first][car[cur].second] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;

			if (visited[ny][nx] == -1 && input[ny][nx] != 'X') {
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < park.size(); i++) {

		if (visited[park[i].first][park[i].second] == -1)
			dist[cur][i] = INF;
		else {
			g[cur].push_back(i);
			dist[cur][i] = visited[park[i].first][park[i].second];
		}
	}
}

bool dfs(int cur, int m)
{
	if (v[cur]) return false;

	v[cur] = true;

	for (auto i : g[cur]) {
		if (dist[cur][i] > m) continue;

		if (match[i]==-1 || dfs(match[i], m)) {
			match[i] = cur;
			return true;
		}
	}

	return false;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &r, &c);
	getchar();

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%c", &input[i][j]);

			if (input[i][j] == 'C')
				car.push_back({ i, j });
			else if (input[i][j] == 'P')
				park.push_back({ i, j });
		}
		getchar();
	}
	
	if (car.size() == 0) {
		printf("0\n");
		return 0;
	}
	
	if (car.size() > park.size()) {
		printf("-1\n");
		return 0;
	}

	for (i = 0; i < car.size(); i++) bfs(i);

	int solve=-1, tmp, s=0, e=10000, m;

	while (s <= e) {

		m = (s + e) / 2;
		tmp = 0;

		memset(match, -1, sizeof(match));
		for (i = 0; i < car.size(); i++) {
			memset(v, 0, sizeof(v));
			if (dfs(i, m)) tmp++;
		}

		if (tmp == car.size()) {
			solve = m;
			e = m - 1;
		}
		else
			s = m + 1;
	}

	printf("%d\n", solve);
}