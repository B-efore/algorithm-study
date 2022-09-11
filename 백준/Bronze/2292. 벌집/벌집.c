#include <stdio.h>
int bee(int n);
int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n", bee(n));

	return 0;
}
int bee(int n)
{
	int min=1, max=1, i=1;

	while(1)
	{
		if((n>=min)&&(n<=max))
			break;

		min = max+1;
		max += 6*i;
		i++;
	}

	return i;
}