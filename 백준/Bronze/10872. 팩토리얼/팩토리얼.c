#include <stdio.h>
int facto(int n);
int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n", facto(n));
	return 0;
}
int facto(int n)
{
	if (n==1||n==0)
		return 1;
	else
		return (n * facto(n-1));
}