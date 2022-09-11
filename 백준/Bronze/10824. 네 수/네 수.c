#include <stdio.h>
int main(void)
{
	long long i, tmp, sum = 0;
	long long num[4];

	for (i = 0; i < 4; i++)
		scanf("%lld", &num[i]);

	for (i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			tmp = num[i + 1];

			while (tmp>0)
			{
				num[i]*=10;
				tmp /= 10;
			}

			sum += num[i];
		}
		else
			sum += num[i];
	}

	printf("%lld\n", sum);
	return 0;
}