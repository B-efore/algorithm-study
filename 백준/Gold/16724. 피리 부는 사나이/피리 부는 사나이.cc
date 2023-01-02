#include <stdio.h>
#define N 1000
char map[N+1][N+1];
int g[N+1][N+1];
int n, m, check=1, ans;
void solve(int y, int x)
{
	if(g[y][x]==0){

		g[y][x]=check;
	
		if(map[y][x]=='U') solve(y-1, x);
		else if(map[y][x]=='L') solve(y, x-1);
		else if(map[y][x]=='R') solve(y, x+1);
		else if(map[y][x]=='D') solve(y+1, x);
	}
	else if(g[y][x]==check){
		ans++;
		return;
	}
	else
		return;
}
int main(void)
{
	scanf("%d %d", &n, &m);
	getchar();

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%c", &map[i][j]);
		}
		getchar();
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!g[i][j]) {
				solve(i, j);
                check++;
			}
		}
	}

	printf("%d\n", ans);
}