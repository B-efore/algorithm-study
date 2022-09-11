#include <stdio.h>
#include <math.h>
void Prime(int, int);
int main(void)
{
	int m, n;
	scanf("%d %d", &m, &n);

	Prime(m, n);
	return 0;
}
void Prime(int m, int n)
{
	int i, s, count;

	for(;m<=n; m++)
	{
		s = (int)sqrt(m);

		for(i=2; i<=s; i++)
			if (m%i==0)
			{
				i=0;
				break;
			}

		if (i!=0&&m!=1)
			printf("%d\n", m);
	}
}