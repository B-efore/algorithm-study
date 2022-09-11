#include <stdio.h>
int main(void)
{
	int i, j, num, n[5];

	while (1)
	{
		i = 0; j = 0;
		scanf("%d", &num);

		if (num == 0)
			break;

		while (num > 0)
		{
			n[i++] = num % 10;
			num /= 10;
		}

		while (i > j)
		{
			if (n[j] != n[i-1])
			{
				num = -1;
				break;
			}

			j++; i--;
		}

		if (num == -1)
			printf("no\n");
		else
			printf("yes\n");

	}

	return 0;
}