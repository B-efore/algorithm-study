#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50
#define INF 987654321

char number[N + 1][N + 1];
bool visit[N + 1][N + 1];
int dp[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int n, m;
int DFS(int y, int x);
int main(void)
{
	scanf("%d %d", &n, &m);
	getchar();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%c", &number[i][j]);
		getchar();
	}

	memset(dp, -1, sizeof(dp));
	DFS(0, 0);
	printf("%d\n", dp[0][0] + 1);

	return 0;
}

int DFS(int y, int x)
{
	if (visit[y][x] == 1) {
		printf("-1\n");
		exit(0);
	}

	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {

		int ny = y + dy[i] * (number[y][x] - '0');
		int nx = x + dx[i] * (number[y][x] - '0');

		if (ny >= n || ny < 0 || nx >= m || nx < 0 || number[ny][nx] == 'H') continue;

		dp[y][x] = max(dp[y][x], DFS(ny, nx) + 1);
	}

	visit[y][x] = false;
	return dp[y][x];
}