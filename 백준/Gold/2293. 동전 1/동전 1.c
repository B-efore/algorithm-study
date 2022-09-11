#include <stdio.h>
#define N 100
#define K 10000
int coin[N + 1];
int dp[K + 1];
int main(void)
{
	int i, j, n, k;
	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	dp[0] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= k; j++) {
			if(j-coin[i]>=0)
				dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}