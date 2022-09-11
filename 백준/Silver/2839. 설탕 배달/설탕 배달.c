#include <stdio.h>
int main(void)
{
	int n, a, b, sum;
	scanf("%d", &n);

	sum=2000;

	for(int i=0; i<=n/5; i++)
	{
		for(int j=0; j<=n/3; j++)
		{
			if ((3*j)+(5*i)==n)
			{
				if (i+j<sum)
					sum=i+j;
			}
		}
	}

	if(sum==2000)
		sum=-1;

	printf("%d\n", sum);
	return 0;
}