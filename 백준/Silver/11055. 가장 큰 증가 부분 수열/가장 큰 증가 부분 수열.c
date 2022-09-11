#include <stdio.h>
#define N 1000
//i번째 원소까지 포함했을 때, 가장 큰 증가 부분 수열의 합
int L[N+1];
int number[N+1];
int main(void)
{
	int i, j, n, max;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", &number[i]);

	for(i=1; i<=n; i++){

		max = 0;

		for(j=1; j<i; j++){
			if(number[i] > number[j]){
				if(max < L[j])
					max = L[j];
			}
		}

		L[i] = max + number[i];
	}

	max = 0;

	for(i=1; i<=n; i++){
		if(max < L[i])
			max = L[i];
	}

	printf("%d\n", max);
	return 0;
}