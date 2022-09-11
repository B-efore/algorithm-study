#include <stdio.h>
int main(void)
{
	int i, n, tmp;
	int arr[2001]={0};
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		arr[tmp+1000]++;
	}

	for(i=0; i<2001; i++)
		if(arr[i]!=0)
			printf("%d ", i-1000);
	printf("\n");

	return 0;
}