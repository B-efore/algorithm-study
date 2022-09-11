#include <cstdio>
#include <queue>
#define N 100
using namespace std;

int n, m;
int g[N + 1][N + 1];
int visit[N + 1][N + 1], length[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	length[i][j] = 1;
	visit[i][j] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (g[ny][nx] == 1 && visit[ny][nx] == 0) {
				length[ny][nx] = length[y][x] + 1;
				visit[ny][nx] = 1;
				q.push({ ny, nx });
			}

		}
	}

}

int main(void)
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &g[i][j]);
		}
	}

	BFS(0, 0);
	printf("%d\n", length[n-1][m-1]);
	return 0;
}