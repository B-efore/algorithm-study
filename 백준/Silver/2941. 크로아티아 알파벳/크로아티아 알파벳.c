#include <stdio.h>
int main(void)
{
	int num=0, i=0;
	char alp[101];
	scanf("%s", alp);

	while(alp[i]!='\0')
	{
		if (alp[i+1]=='=')
		{
			i+=2;
			num++;
			continue;
		}
		else if ((alp[i]=='d')&&(alp[i+1]=='z')&&(alp[i+2]=='='))
		{
			i+=3;
			num++;
			continue;
		}
		else if (alp[i+1]=='-')
		{
			i+=2;
			num++;
			continue;
		}
		else if ((alp[i]=='n')||(alp[i]=='l'))
		{
			if (alp[i+1]=='j')
			{
				i+=2;
				num++;
				continue;
			}
		}
		else
			;
		i++;
		num++;
	}
	printf("%d\n", num);
	return 0;
}