#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void * b);
int main(void)
{
	int n, i;
	scanf("%d", &n);

	int * arr = (int *)calloc(sizeof(int), n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	for(i=0; i<n; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	return 0;
}