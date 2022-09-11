#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n, k, i, sum=0;
	scanf("%d %d", &n, &k);

	int * coin = (int *)malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
		scanf("%d", &coin[i]);

	for(i=n-1; i>=0; i--)
	{
		if(k/coin[i]<1)
			continue;

		sum += k/coin[i];
		k -= (k/coin[i])*coin[i];
	}

	free(coin);
	printf("%d\n", sum);
	return 0;
}