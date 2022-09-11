#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300
#define INF 987654321
using namespace std;

int map[N + 1][N + 1];
int dp[N + 1][N + 1];	// dp[i][j] : i번 도시를 j개의 도시를 거쳐 방문했을 때의 최대 기내식 점수
int n, m, k;
int solve(int a, int b);
int main(void)
{
	int a, b, c, M = 0;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a < b && c > map[a][b])
			map[a][b] = c;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(n, m));
	return 0;
}

int solve(int a, int b)
{
	if (a != 1 && b == 1)
		return dp[a][b] = -INF;
	else if (a == 1)
		return dp[a][b] = 0;

	if (dp[a][b] != -1) return dp[a][b];

	dp[a][b] = -INF;

	for (int i = 1; i < a; i++) {
		if (map[i][a]) {
			dp[a][b] = max(dp[a][b], solve(i, b - 1) + map[i][a]);
		}
	}

	return dp[a][b];
}