#include <stdio.h>
#define N 30
int dp[N + 1];
int main(void)
{
	int n;
	scanf("%d", &n);

	dp[0] = 1; dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {

		dp[i] += dp[i - 2] * dp[2];

		for (int j = 4; (j <= n) && (i - j >= 0); j += 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}