#include <stdio.h>
int GCD(int a, int b)
{
	int i;

	if(a>b)
		i=b;
	else
		i=a;

	while(i>0)
	{
		if((a%i==0)&&(b%i==0))
			break;

		i--;
	}

	return i;
}
int LCM(int a, int b)
{
	int i=a, k=b;

	while(a!=b)
	{
		if(a>b)
			b+=k;
		else
			a+=i;
	}

	return a;
}
int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", GCD(a, b));
	printf("%d\n", LCM(a, b));

	return 0;
}