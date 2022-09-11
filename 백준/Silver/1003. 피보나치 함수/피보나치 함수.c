#include <stdio.h>
void fibo(int n, int arr[][2]);
int main(void)
{
	int t, n;
	int num[41][2]={0};
	num[0][0]=1; num[0][1]=0;
	num[1][0]=0; num[1][1]=1;
	
	scanf("%d", &t);

	for(int i=0; i<t; i++)
	{
		scanf("%d", &n);
		
		if(n>1)
			fibo(n, num);

		printf("%d %d\n", num[n][0], num[n][1]);
	}

	return 0;
}
void fibo(int n, int arr[][2])
{
	int i=1;

	while(arr[n][0]==0&&arr[n][1]==0)
	{
		i++;

		if (arr[i][0]!=0&&arr[i][1])
			continue;

		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}
}