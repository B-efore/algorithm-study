#include <stdio.h>
#include <string.h>
#define N 1000
char str1[N+1];
char str2[N+1];
char p[N+1][N+1];
int L[N+1][N+1];
void printLCS();
int max(int, int);
int main(void)
{
	int len1, len2;
	scanf("%s %s", str1, str2);
	
	len1 = strlen(str1);
	len2 = strlen(str2);

	for(int i=0; i<len1; i++){
		for(int j=0; j<len2; j++){
			if(str1[i]==str2[j]){
				L[i+1][j+1] = L[i][j] + 1;
				p[i+1][j+1] = 'O';
			}
			else{
				if(L[i][j+1] > L[i+1][j]){
					L[i+1][j+1] = L[i][j+1];
					p[i+1][j+1] = 'U';
				}
				else{
					L[i+1][j+1] = L[i+1][j];
					p[i+1][j+1] = 'L';
				}
			}
		}
	}

	printf("%d\n", L[len1][len2]);
	
	if(L[len1][len2]!=0){
		printLCS(len1, len2);
		printf("\n");
	}

	return 0;
}
void printLCS(int i, int j)
{
	if(i<1 || j<1) return;

	if(p[i][j]=='O'){
		printLCS(i-1, j-1);
		printf("%c", str1[i-1]);
	}
	else if(p[i][j]=='U'){
		printLCS(i-1, j);
	}
	else{
		printLCS(i, j-1);
	}
}
int max(int a, int b){
	return (a>b? a: b);
}