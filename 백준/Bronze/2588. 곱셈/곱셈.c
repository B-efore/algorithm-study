#include <stdio.h>
int main(void)
{
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);
	printf("%d\n", n1*(n2%10));
	printf("%d\n", n1*(n2%100-n2%10)/10);
	printf("%d\n", n1*(n2/100));
    printf("%d\n", n1*n2);
	return 0;
}