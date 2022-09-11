#include <stdio.h>
int check(int, int, int);
int main(void)
{
	int a, b, c;
	int right;
	
	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);

		if(a==0&&b==0&&c==0)
			break;

		right=check(a, b, c);
		
		if(right)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
int check(int a, int b, int c)
{
	int tmp;

	if(a>b)
	{
		if(a>c)
		{
			tmp=a;
			a=c;
			c=tmp;
		}
	}
	else
	{
		if(b>c)
		{
			tmp=b;
			b=c;
			c=tmp;
		}
	}

	if(a*a+b*b==c*c)
		return 1;
	else
		return 0;
}