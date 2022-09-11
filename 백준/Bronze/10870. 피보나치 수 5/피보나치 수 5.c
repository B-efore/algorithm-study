#include <stdio.h>
int fibo(int n);
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fibo(n));
	return 0;
}
int fibo(int n)
{
	if (n<2)
		return n;
	else
		return (fibo(n-1) + fibo(n-2));
}