#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
	int x;
	int y;
} Point;
int compare(const void * a, const void * b);
int main(void)
{
	int i, n;
	scanf("%d", &n);

	Point * arr = (Point *)malloc(sizeof(Point)*n);

	for(i=0; i<n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);

	qsort(arr, n, sizeof(Point), compare);

	for(i=0; i<n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	free(arr);
	return 0;
}
int compare(const void *a, const void *b)
{
	Point num1 = *(Point *)a;
	Point num2 = *(Point *)b;

	if(num1.y<num2.y)
		return -1;

	if(num1.y>num2.y)
		return 1;

	if(num1.x<num2.x)
		return -1;
	else if(num1.x>num2.x)
		return 1;
	else
		return 0;
}