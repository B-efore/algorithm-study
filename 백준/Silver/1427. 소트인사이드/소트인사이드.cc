#include <stdio.h>
#include <stdlib.h>
#define N 10
int arr[N + 1];
int compare(const void* a, const void* b);
int main(void)
{
	int i, tmp;

	i = 0;
	while ((tmp = getchar()) != '\n') {
		arr[i] = tmp - '0';
		i++;
	}

	qsort(arr, i, sizeof(int), compare);
	
	while(i--)
		printf("%d", arr[i]);
	printf("\n");
	
	return 0;
}

int compare(const void* a, const void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 == num2) return 0;
	else if (num1 > num2) return 1;
	else return -1;
}