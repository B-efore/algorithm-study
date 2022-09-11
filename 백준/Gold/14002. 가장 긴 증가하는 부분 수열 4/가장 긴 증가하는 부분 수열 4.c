#include <stdio.h>
#include <string.h>
#define N 1000
int p[N+1], L[N+1], number[N+1];
int max, idx;
int main(void)
{
	int i, j, n;

	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
		scanf("%d", &number[i]);

	L[0] = -1; L[1] = number[1]; p[1] = 1;

	for(i=2; i<=n; i++){
		for(j=n; j>=0; j--){

			if(L[j]==0)
				continue;

			if(L[j]<number[i]){
				L[j+1] = number[i];
				p[i] = j+1;

				break;
			}
		}
	}

	for(i=1; i<=n; i++)
		if(max<p[i]){
			max = p[i];
			idx = i;
		}

	printf("%d\n", max);
	j=0;

	for(i=idx; max>0; i--){
		if(p[i]==max){
			L[j] = number[i];
			j++; max--;
		}
	}

	for(i=j-1; i>=0; i--)
		printf("%d ", L[i]);

	return 0;
}