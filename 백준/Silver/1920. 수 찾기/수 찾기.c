#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b);
int target(int arr[], int, int);
int main(void)
{
	int i, n, m, tmp;
	scanf("%d", &n);

	//배열에 값 넣기
	int * arr = (int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	qsort(arr, n, sizeof(int), compare);

	//검사
	scanf("%d", &m);
	int * check = (int *)malloc(sizeof(int)*m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &tmp);
		check[i] = target(arr, n, tmp);
	}

	for(i=0; i<m; i++)
		printf("%d\n", check[i]);

	free(arr);
	free(check);

	return 0;
}
int compare(const void *a, const void *b)
{
	int num1= *(int *)a;
	int num2= *(int *)b;

	if(num1<num2)
		return -1;

	if(num1>num2)
		return 1;

	return 0;
}
int target(int arr[], int m, int num)
{
	int first=0;
	int last=m-1;
	int mid;

	while(first<=last)
	{
		mid = (first+last)/2;
		if (num == arr[mid])
			return 1;
		else
		{
			if (num>arr[mid])
				first = mid+1;
			else
				last = mid-1;
		}
	}
	return 0;
}