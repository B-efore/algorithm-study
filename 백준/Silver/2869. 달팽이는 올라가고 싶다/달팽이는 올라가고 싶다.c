#include <stdio.h>
int main(void)
{
	int a, b, v, sum=0, day=0;
	scanf("%d %d %d", &a, &b, &v);

	day=(v-a)/(a-b);
	sum=v-day*(a-b);

	while(sum!=0)
	{
		sum-=a;
		day++;

		if(sum<=0)
			break;

		sum+=b;
	}
	printf("%d\n", day);
	return 0;
}