#include <stdio.h>
int main(void)
{
	double n1, n2;
	scanf("%lf %lf", &n1, &n2);
	printf("%.16lf\n", n1/n2);
	return 0;
}