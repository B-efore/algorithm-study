#include <stdio.h>
#include <string.h>
#define INF 987654321
#define M 500
#define N 100
// 연결된 전봇대의 정보
int line[M+1];
// i: 교차하지 않고 연결할 수 있는 최대 전깃줄 개수에서 마지막 번호
int dp[N+1];
int Bsearch(int, int, int);
int main(void)
{
	int i, j, n, idx, max=0;
	scanf("%d", &n);

	for(int k=1; k<=n; k++){
		scanf("%d %d", &i, &j);
		line[i] = j;
	}
	
	for(i=1; i<=N; i++)
		dp[i] = INF;

	dp[0] = -INF;

	for(i=1; i<=M; i++){
		if(line[i]==0) continue;

		idx = Bsearch(line[i], 1, N);
		dp[idx] = line[i];

		if(idx>max)
			max = idx;
	}


	printf("%d\n", n-max);
	return 0;
}
int Bsearch(int number, int start, int end)
{
	int mid;

	while(start<=end){
	
		mid = (start + end) / 2;

		if(dp[mid] > number){
			end = mid - 1;
		}
		else{
			start = mid + 1;
		}
	}

	return start;
}