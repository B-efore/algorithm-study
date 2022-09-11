#include <stdio.h>
#include <string.h>
#define N 500
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int g[N + 1][N + 1];
int dp[N + 1][N + 1];
int n;
int solve(int y, int x);
int main(void)
{
	int max, tmp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);

	memset(dp, -1, sizeof(dp));
	max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp = solve(i, j);

			if (max < tmp)
				max = tmp;
		}
	}
	
	printf("%d\n", max);
	return 0;
}

int solve(int y, int x)
{
	if (dp[y][x] != -1) return dp[y][x];

	int tmp = 1;
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (g[ny][nx] > g[y][x]) {
			tmp = solve(ny, nx) + 1;

			if (dp[y][x] < tmp)
				dp[y][x] = tmp;
		}
	}

	return dp[y][x];
}