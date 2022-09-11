#include <stdio.h>
int main(void)
{
	int i, n, k, num=0;
	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			num++;

			if (num == k)
			{
				printf("%d\n", i);
				n = 0;
				break;
			}
		}
	}

	if (n != 0)

		printf("0\n");

	return 0;
}