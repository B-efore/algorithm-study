#include <stdio.h>
#include <string.h>
#define N 17000
//delete
#define U 0
//add
#define L 1
//modify
#define UL 2
//copy
#define M 3

typedef struct path{
	unsigned char p1 : 2;
	unsigned char p2 : 2;
	unsigned char p3 : 2;
	unsigned char p4 : 2;
} Path;

Path path[N/2+1][N/2+1];
int p[2][N+2];
char s1[N+1], s2[N+1];

void printLCS(int, int);
void setPath(int, int, char);
char getPath(int, int);
int main(void)
{
	int i, j, len1, len2;
	int n1, n2, n3, tmp;

	scanf("%s %s", s1, s2);

	len1 = strlen(s1);
	len2 = strlen(s2);

	p[0][0] = 0;

	for(i=1; i<=N; i++){
		p[0][i] = i;
		setPath(i, 0, U);
		setPath(0, i, L);
	}

	for(i=1; i<=len1; i++){
		for(j=1; j<=len2; j++){

			if(j==1){
				p[i%2][0] = i;
			}

			tmp = 1;

			if(s1[i-1]==s2[j-1])
			{
				tmp = 0;
				p[i%2][j] = p[(i-1)%2][j-1]+tmp;
				setPath(i, j, M);
			}
			else
			{
				n1 = p[(i-1)%2][j-1]+tmp;
				n2 = p[(i-1)%2][j]+1;
				n3 = p[i%2][j-1]+1;

				if(n1<=n2 && n1<=n3)
				{
					p[i%2][j] = n1;
					setPath(i, j, UL);
				}
				else if(n2<=n1 && n2<=n3)
				{
					p[i%2][j] = n2;
					setPath(i, j, U);
				}
				else
				{
					p[i%2][j] = n3;
					setPath(i, j, L);
				}
			}
		}
	}

	printLCS(len1, len2);
	return 0;
}
void printLCS(int i, int j)
{
	if(i<=0&&j<=0){
		return;
	}

	char tmp = getPath(i, j);

	if(tmp==M)
	{
		printLCS(i-1, j-1);
		printf("c %c\n", s2[j-1]);
	}
	else if(tmp==UL)
	{
		printLCS(i-1, j-1);
		printf("m %c\n", s2[j-1]);
	}
	else if(tmp==L)
	{
		printLCS(i, j-1);
		printf("a %c\n", s2[j-1]);
	}
	else if(tmp==U)
	{
		printLCS(i-1, j);
		printf("d %c\n", s1[i-1]);
	}
}
void setPath(int i, int j, char c)
{
	if(i%2==0 && j%2==0){
		path[i/2][j/2].p1 = c;
	}
	else if(i%2==0){
		path[i/2][j/2].p2 = c;
	}
	else if(j%2==0){
		path[i/2][j/2].p3 = c;
	}
	else{
		path[i/2][j/2].p4 = c;
	}

//	printf("i:%d, j:%d, c:%d\n", i, j, c);
}
char getPath(int i, int j)
{
	if(i%2==0 && j%2==0){
		return path[i/2][j/2].p1;
	}
	else if(i%2==0){
		return path[i/2][j/2].p2;
	}
	else if(j%2==0){
		return path[i/2][j/2].p3;
	}
	else{
		return path[i/2][j/2].p4;
	}
}