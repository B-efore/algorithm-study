#include <stdio.h>
#define K 100000
#define N 100

int W[N + 1], V[N + 1];
int dp[K + 1];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) 
		scanf("%d %d", &W[i], &V[i]);

	for (int i = 0; i < n; i++) {
		for (int j = k; j >= W[i]; j--) {
			if (dp[j - W[i]] + V[i] > dp[j]) dp[j] = dp[j - W[i]] + V[i];
			else dp[j] = dp[j];
		}
	}

	printf("%d\n", dp[k]);
	return 0;
}