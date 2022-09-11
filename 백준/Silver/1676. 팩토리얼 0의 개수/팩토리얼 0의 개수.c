#include <stdio.h>
int abs(int, int);
int main(void)
{
	int i, n, tmp, t=0, f=0;
	scanf("%d", &n);


	for (i = 1; i <= n; i++)
	{
		tmp = i;

		while (!(tmp % 2))
		{
			t++;
			tmp /= 2;
		}
		
		while (!(tmp % 5))
		{
			f++;
			tmp /= 5;
		}
	}

	printf("%d\n", abs(t, f));
	return 0;
}
int abs(int a, int b)
{
	return a < b ? a : b;
}