#include <cstdio>
#include <stack>
#include <algorithm>
#define N 25
using namespace std;

int n, cnt = 0;
int map[N + 1][N + 1], Number[N*N + 1], visit[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void solve(int y, int x)
{
	stack<pair<int, int>> s;
	s.push({ y, x });
	visit[y][x] = 1;
	cnt++; Number[cnt]++;

	while (!s.empty()) {

		int tmp_y = s.top().first;
		int tmp_x = s.top().second;
		s.pop();

		for (int i = 0; i < 4; i++) {
			int ny = tmp_y + dy[i];
			int nx = tmp_x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (map[ny][nx] == 1 && visit[ny][nx]==0) {
				Number[cnt]++;
				visit[ny][nx] = 1;
				s.push({ ny, nx });
			}
		}
	}
}

int main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (visit[i][j]==0 && map[i][j]==1)
				solve(i, j);
	}

	printf("%d\n", cnt);

	sort(Number + 1, Number + cnt + 1);
	for (int i = 1; i <= cnt; i++)
		printf("%d\n", Number[i]);

	return 0;
}

