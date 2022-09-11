#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1<num2)
		return -1;

	if(num1>num2)
		return 1;

	return 0;
}
int main(void)
{
	int i, n, s=0;
	scanf("%d", &n);

	int * a = (int *)malloc(sizeof(int)*n);
	int * b = (int *)malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<n; i++)
		scanf("%d", &b[i]);


	qsort(a, n, sizeof(int), compare);
	qsort(b, n, sizeof(int), compare);

	for(i=0; i<n; i++)
		s+=a[i]*b[n-i-1];

	printf("%d\n", s);
	return 0;
}