#include <stdio.h>
#include <stdlib.h>
int ab(int, int);
int main(void)
{
	int i=0, j=1, k=2, n, m, sum, check=0;
	scanf("%d %d", &n, &m);

	//n개의 카드 지급
	int * card = (int *)malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &card[i]);

	//3개의 카드 정하기
	for(i=0; i<j; i++)
	{
		sum=0;
		for(j=i+1; j<k; j++)
		{
			for(k=j+1; k<n; k++)
			{
				sum = card[i]+card[j]+card[k];

				if (sum<=m)
				{
					if((m-sum)<(m-check))
						check = sum;
				}
			}
		}
	}
	printf("%d\n", check);
	free(card);
	return 0;
}