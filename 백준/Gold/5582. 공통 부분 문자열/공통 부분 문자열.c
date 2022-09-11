#include <stdio.h>
#include <string.h>
#define N 4000
char str1[N+1];
char str2[N+1];
//원소 i, j까지 검사했을 때 가장 긴 공통 부분 문자열의 길이
int L[N+1][N+1];
int main(void)
{
	int i, j, len1, len2, max=0;
	scanf("%s %s", str1, str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for(i=0; i<len1; i++){
		for(j=0; j<len2; j++){
			if(str1[i]==str2[j]){
				L[i+1][j+1] += L[i][j] + 1;

				if(max<L[i+1][j+1])
					max = L[i+1][j+1];
			}
		}
	}

	printf("%d\n", max);
	return 0;
}