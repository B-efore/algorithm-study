#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNIGS
#endif

#include <stdio.h>
int main(void)
{
	int i, j, a, b, t, tmp;
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &a, &b);

		tmp = a;

		for (j = 1; j < b % 4 + 4; j++)
			tmp *= a%10;

		tmp = tmp % 10;

		if (tmp == 0)
			printf("10\n");
		else
			printf("%d\n", tmp);
	}

	return 0;
}