#include <stdio.h>
int main(void)
{
	int a, b, c, n;
	scanf("%d %d %d", &a, &b, &c);

	if (c-b<=0)
		printf("-1\n");
	else
	{
		n=a/(c-b)+1;
		printf("%d\n", n);
	}

	return 0;
}
