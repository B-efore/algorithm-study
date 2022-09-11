#include <stdio.h>
int main(void)
{
	int i, j, tmp, n, num=0;
	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		scanf("%d", &tmp);

		for(j=2; j<=tmp; j++)
		{
			if (j==tmp)
				num++;
			if (tmp%j==0)
				break;
		}

	}

	printf("%d\n", num);
	return 0;
}