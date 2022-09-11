#include <stdio.h>
#define DIV 1000000000
#define N 200
#define K 200
// k개를 더했을 때 합이 n이 되는 경우
long long dp[K + 1][N + 1];
int main(void)
{
	int i, j, q, n, k;
	scanf("%d %d", &n, &k);

	for (i = 0; i <= n; i++)
		dp[1][i] = 1;

	for (j = 2; j <= k; j++) {
		for (i = 0; i <= n; i++) {
			for (q = 0; q <= i; q++) {
				dp[j][i] += dp[j - 1][i - q];
			}
			dp[j][i] %= DIV;
		}
	}

	printf("%ld\n", dp[k][n]);
	return 0;
}