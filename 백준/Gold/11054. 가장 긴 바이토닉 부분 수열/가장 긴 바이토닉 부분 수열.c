#include <stdio.h>
#define N 1000
int number[N+1];
//왼쪽에서 시작해서 오른쪽으로 증가하는, i번째 원소까지의  LCS의 길이
int leftL[N+1];
//오른쪽에서 시작해서 왼쪽으로 증가하는, i번째 원소까지의 LCS의 길이
int rightL[N+1];
int main(void)
{
	int i, j, n, tmp, max;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", &number[i]);


	//1. leftL 구하기
	leftL[1] = 1;

	for(i=1; i<=n; i++){

		max = 0;

		for(j=1; j<i; j++){
			if(number[j] < number[i]){
				if(leftL[j] > max)
					max = leftL[j];
			}
		}

		leftL[i] = max + 1;
	}

	// 2. rightL 구하기
	rightL[n] = 1;
	
	for(i=n; i>=1; i--){

		max = 0;

		for(j=n; j>i; j--){
			if(number[j] < number[i]){
				if(rightL[j] > max)
					max = rightL[j];
			}
		}

		rightL[i] = max + 1;
	}

	max = 0;

	// 3. 합체
	for(i=1; i<=n; i++){
		tmp = leftL[i] + rightL[i] - 1;

		if(max < tmp)
			max = tmp;
	}

	printf("%d\n", max);
	return 0;
}