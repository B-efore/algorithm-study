#include <cstdio>
#define N 50
int arr[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int m, n, k;
void DFS(int y, int x);
int main(void)
{
	int x, y, t, ans = 0;
	scanf("%d", &t);

	while (t--) {
		ans = 0;
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			arr[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j]) {
					DFS(i, j);
					ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}

void DFS(int y, int x)
{
	arr[y][x] = 0;

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
		if (arr[ny][nx]) DFS(ny, nx);
	}
}