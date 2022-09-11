#include <stdio.h>
int main(void)
{
	int j, i, m, n, check, num, sum=0;
	scanf("%d %d", &m, &n);

		for (i = m; i <= n; i++)
		{
			check = 0;

			for (j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					check = 1;
					break;
				}
			}

			if((check!=1)&&(sum==0))
				num = i;

			if ((check != 1)&&(i!=1))
				sum += i;
		}

		if (sum == 0)
			printf("-1\n");
		else
		{
			printf("%d\n", sum);
			printf("%d\n", num);
		}

		return 0;
}