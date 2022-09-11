#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define N 1120
#define K 14
bool p[N+1];
//K+1개의 소수를 사용할 수 있을 때 i를 나타낼 수 있는 개수
int prime[N+1];
int dp[K+1][N+1];
void setPrime();
int solve(int, int, int);
int main(void)
{
	//에라토스테네스의 체
	memset(p, true, sizeof(p));
	setPrime();

	int j = 1;

	for(int i=2; i<=N; i++){
		if(p[i]){
			prime[j]=i;
			j++;
		}
	}

	int i, t, n, k, tmp;
	scanf("%d", &t);

	for(i=1; i<=t; i++){
		scanf("%d %d", &n, &k);
		memset(dp, 0, sizeof(dp));
		printf("%d\n", solve(k, n, j));
	}


	return 0;
}
int solve(int k, int n, int len)
{
	dp[0][0] = 1;

	for(int i=1; i<len; i++){
		for(int j=n; j>=prime[i]; j--){
			for(int k=1; k<=14; k++){
				dp[k][j] += dp[k-1][j-prime[i]];
			}
		}
	}

	return dp[k][n];
}
void setPrime()
{
	p[0] = false;
	p[1] = false;
	
	for(int i=2; i<=sqrt(N); i++){
		for(int j=i*2; j<=N; j+=i){
			if(p[i])
				p[j] = false;
			
		}
	}
}