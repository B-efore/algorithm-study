#include <stdio.h>
#define N 100
#define L 10
#define DIV 1000000000
//길이가 N일 때, 마지막 수가 L인 경우의 수
long long dp[N + 1][L + 1];
int main(void)
{
	int n;
	scanf("%d", &n);
	
	// 한 자리 수인 경우
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][1] % DIV;
			else if (j == 9) dp[i][j] = dp[i - 1][8] % DIV;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % DIV;
		}
	}

	long long sol = 0;

	for (int j = 0; j <= 9; j++)
		sol += dp[n][j];

	printf("%lld\n", sol%DIV);
	return 0;
}