#include <stdio.h>
#define K 100
#define T 10000
// i가 되는 가지수
int dp[T+1];
int main(void)
{
	int i, j, l, t, k, a, b;
	scanf("%d %d", &t, &k);

	dp[0] = 1;

	for(i=1; i<=k; i++){

		scanf("%d %d", &a, &b);

		for(j=t; j>=a; j--){

			for(l=1; l<=b; l++){
				if(j - l * a >= 0)
					dp[j] += dp[j - l * a];
			}

		}
	}

	printf("%d\n", dp[t]);
	return 0;
}