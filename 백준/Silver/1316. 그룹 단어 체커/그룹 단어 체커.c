#include <stdio.h>
void initarray(int check[]);
int main(void)
{
	int n, num, tmp, j, i;
	int check[26]={0};
	char alp[100]={0};
	
	scanf("%d", &n);
	num=n;

	i=0;
	while(i<n)
	{
		initarray(check);
		scanf("%s", alp);
		j=0;

		while(alp[j]!='\0')
		{
			tmp = alp[j]-97;
			check[tmp]++;

			if ((check[tmp]>1)&&(alp[j-1]!=alp[j]))
			{
				num--;
				break;
			}
			j++;
		}
		i++;
	}
	printf("%d\n", num);
	return 0;
}
void initarray(int check[26])
{
	for(int i=0; i<26; i++)
		check[i]=0;
}