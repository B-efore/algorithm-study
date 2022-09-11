#include <stdio.h>
#include <string.h>
#define N 50
#define M 50
#define div 1000007
int n, m;
int C[N+1][M+1];
int sum[N+1][M+1][N+1][N+1];
int pathSum(int, int, int, int);
int main(void)
{
	int i, j, x, y, c;
	scanf("%d %d %d", &n, &m, &c);

	memset(sum, -1, sizeof(sum));

	for(i=1; i<=c; i++){
		scanf("%d %d", &y, &x);
		C[y][x]=i;
	}

	for(i=0; i<=c; i++){
			printf("%d ", pathSum(1, 1, i, 0));
	}
	printf("\n");

	return 0;
}
int pathSum(int y, int x, int cnt, int prev){

	if(y>n||x>m||cnt<0)
		return 0;

    //값 넣기 시작
	if(y==n && x==m){
		if(cnt==0 && C[y][x]==0) return 1;
		if(cnt==1 && C[y][x]>prev) return 1;
		return 0;
	}

    //이미 방문했다면
	if(sum[y][x][cnt][prev]!=-1)
		return sum[y][x][cnt][prev];

	sum[y][x][cnt][prev] = 0;
	
	if(C[y][x]==0)
		sum[y][x][cnt][prev] = (pathSum(y+1, x, cnt, prev) + pathSum(y, x+1, cnt, prev))%div;
	else if(C[y][x]>prev)
		sum[y][x][cnt][prev] = (pathSum(y+1, x, cnt-1, C[y][x]) + pathSum(y, x+1, cnt-1, C[y][x]))%div;

	return sum[y][x][cnt][prev];
}