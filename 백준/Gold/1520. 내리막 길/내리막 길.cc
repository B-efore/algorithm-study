#include <stdio.h>
#include <string.h>
#define N 500
int m, n;
int g[N + 1][N + 1];
int dp[N + 1][N + 1];
int solve(int y, int x);
int main(void)
{
	scanf("%d %d", &m, &n);

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &g[i][j]);
	
	memset(dp, -1, sizeof(dp));
	dp[m][n] = 1;

	printf("%d\n", solve(1, 1));
	return 0;
}

int solve(int y, int x)
{
	if (y < 1 || y > m || x < 1 || x > n) return 0;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;

	if (g[y][x] > g[y - 1][x]) dp[y][x] += solve(y - 1, x);
	if (g[y][x] > g[y + 1][x]) dp[y][x] += solve(y + 1, x);
	if (g[y][x] > g[y][x - 1]) dp[y][x] += solve(y, x - 1);
	if (g[y][x] > g[y][x + 1]) dp[y][x] += solve(y, x + 1);

	return dp[y][x];
}