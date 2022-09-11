#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define N 1000
using namespace std;

int m, n, ans;
bool visit[N + 1][N + 1];
int map[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int main(void)
{
	scanf("%d %d", &m, &n);

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || visit[ny][nx]) continue;

			visit[ny][nx] = true;

			if (!map[ny][nx]) {
				map[ny][nx] = map[y][x] + 1;
				q.push({ ny, nx });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				printf("-1\n");
				exit(0);
			}
			ans = max(ans, map[i][j]);
		}
	}

	printf("%d\n", ans - 1);
	return 0;
}