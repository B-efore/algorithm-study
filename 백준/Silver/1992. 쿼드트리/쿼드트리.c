#include <stdio.h>
#define N 64
char data[N][N];
void divide(int, int, int);
int main(void){

	int n;

	scanf("%d", &n);

	for(int i=0; i<n; i++)
			scanf("%s", &data[i]);

	divide(n, 0, 0);
	return 0;
}
void divide(int n, int x, int y){
	
	char check = data[x][y];

	if(n==1){
		printf("%c", check);
		return;
	}

	for(int i=x; i<x+n; i++)
		for(int j=y; j<y+n; j++)
			if(data[i][j]!=check)
			{
				printf("(");
				
				n/=2;

				divide(n, x+n*0, y+n*0);
				divide(n, x+n*0, y+n*1);
				divide(n, x+n*1, y+n*0);
				divide(n, x+n*1, y+n*1);
				
				printf(")");

				return;
			}

	printf("%c", check);
}