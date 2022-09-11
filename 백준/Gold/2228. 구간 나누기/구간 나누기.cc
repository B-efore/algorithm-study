#include <cstdio>
#include <algorithm>
#define N 100
#define INF -987654321
using namespace std;
int sum[N + 1]; // i번 원소까지 누적합
int dp[N + 1][N + 1]; // i번 원소까지 j개의 구간을 선택했을 때 최대 값
int main(void)
{
	int n, m, tmp;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &tmp);
		sum[i] += sum[i - 1] + tmp;
	}

	// 초기화
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = INF;

	// dp[1][1]
	dp[1][1] = sum[1];

	// dp[2][1] ~ dp[n][1], 하나의 구간만 선택
	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][1];

		for (int j = 0; j <= i - 1; j++) {
			dp[i][1] = max(dp[i][1], sum[i] - sum[j]);
		}
	}

	// 두 개 이상의 구간을 선택
	for (int i = 3; i <= n; i++) {
		for (int j = 2; j <= m; j++) {

			dp[i][j] = dp[i - 1][j];

			for (int k = 1; k <= i - 2; k++) {
				dp[i][j] = max(dp[i][j], dp[k][j - 1] + sum[i] - sum[k + 1]);
			}
		}
	}

	printf("%d\n", dp[n][m]);
	return 0;
}