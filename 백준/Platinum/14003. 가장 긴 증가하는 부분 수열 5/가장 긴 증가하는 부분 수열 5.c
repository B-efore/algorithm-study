#include <stdio.h>
#define INF 1987654321
#define N 1000000
int number[N+1];
// 길이가 i일 때 가장 마지막 원소
int L[N+1];
int p[N+1];
int binarySearch(int, int, int);
void printL(int, int);
int main(void)
{
	int i, j, n, idx, max;
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		scanf("%d", &number[i]);

	for(i=1; i<=n; i++)
		L[i] = INF;

	L[1] = number[1];
	p[1] = 1;

	for(i=2; i<=n; i++){
		idx = binarySearch(number[i], 1, i-1);
		L[idx] = number[i];
		p[i] = idx;
	}

	for(i=n; i>=1; i--){
		if(L[i]!=INF){
			printf("%d\n", i);
			max = i;
			break;
		}
	}

	printL(n, max);
	printf("\n");
	return 0;
}
void printL(int i, int num)
{
	if(i==0||num==0) return;

	if(p[i]==num){
		printL(i-1, num-1);
		printf("%d ", number[i]);
	}
	else
		printL(i-1, num);
}
int binarySearch(int num, int start, int end)
{
	int mid;

	while(start<=end){

		mid = (start+end)/2;

		if(L[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}

//	printf("num: %d, L[%d] : %d\n", num, start,  L[start]);
	return start;
}