#include <stdio.h>
int main(void)
{
	int i, n, tmp;
	scanf("%d", &n);

	//배열 받기
	int arr[10000] = {0};
	for(i=0; i<n; i++)
	{
		scanf("%d", &tmp);
		arr[tmp-1]++;
	}

	//배열 출력
	for(i=0; i<10000; i++)
	{
		if (arr[i]>0)
		{
			for(int j=0; j<arr[i]; j++)
				printf("%d\n", i+1);
		}
	}
	return 0;
}