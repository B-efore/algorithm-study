#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 100
#define K 50

bool map[N+1][N+1][2];
long long int dp[N+1][N+1];
long long int solve(int, int, int, int);
int main(void)
{
	int i, j, n, m, k;
	scanf("%d %d", &n, &m);
	scanf("%d", &k);

	int a, b, c, d;

	for(i=1; i<=k; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(a<c) map[c][d][0] = 1;
		else if(a>c) map[a][b][0] = 1;
		else if(b<d) map[c][d][1] = 1;
		else if(b>d) map[a][b][1] = 1;
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	printf("%lld\n", solve(n, m, n, m));

	/*
	for(i=0; i<=n; i++){
		for(j=0; j<=m; j++)
			printf("%lld ", dp[i][j]);
		printf("\n");
	}
	*/


	return 0;
}
long long int solve(int n, int m, int i, int j)
{
	if(i==0 && j ==0) return dp[0][0];
	if(i<0 || j<0) return 0;	
	if(dp[i][j] != -1) return dp[i][j];

	dp[i][j] = 0;

	if(map[i][j][0] && map[i][j][1])
		dp[i][j] = 0;
	else if(map[i][j][0])
		dp[i][j] += solve(n, m, i, j-1);
	else if(map[i][j][1])
		dp[i][j] += solve(n, m, i-1, j);
	else
		dp[i][j] += solve(n, m, i-1, j) + solve(n, m, i, j-1);

	return dp[i][j];
}