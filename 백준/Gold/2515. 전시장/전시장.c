#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 300000
typedef struct picture{
	int h;
	int c;
} Picture;
Picture picture[N+1];
int n, s;
int sum[N+1];
int check[N+1];
int compare(const void *, const void *);
int bSearch(int);
int main(void)
{
	int i, j, n1, n2, tmp;
	scanf("%d %d", &n, &s);

	for(i=1; i<=n; i++)
		scanf("%d %d", &picture[i].h, &picture[i].c);

	qsort(picture, n+1, sizeof(Picture), compare);
	
	for(i=n; i>=1; i--){

		if(i==n)
			sum[i] = picture[i].c;
		else
		{
			n1 = sum[i+1];
			tmp = bSearch(i);

			if(tmp <= n)
				n2 = sum[tmp] + picture[i].c;
			else
				n2 = picture[i].c;

			if(n1>=n2)
				sum[i] = n1;
			else
				sum[i] = n2;
		}
	}


	printf("%d\n", sum[1]);
	return 0;
}
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
int bSearch(int r)
{
	int left, mid, right, diff;

	left = r+1;
	right = n;

	while(left<=right)
	{
		mid = (left + right)/2;

		diff = picture[mid].h - picture[r].h;

		if(diff>=s) right = mid - 1;
		else left = mid + 1;
	}

	return left;
}