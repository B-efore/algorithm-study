#include <stdio.h>
int main(void)
{
	int i, n, sum, tmp, check=0;
	scanf("%d", &n);

	for (i = 1; i < n; i++)
	{
		sum = i;
		tmp = i;

		while (tmp > 0)
		{
			sum += tmp % 10;
			tmp /= 10;
		}

		if (sum == n)
		{
			sum = i;
			check = 1;
			break;
		}
	}

	if (check == 1)
		printf("%d\n", sum);
	else
		printf("0\n");

	return 0;
}