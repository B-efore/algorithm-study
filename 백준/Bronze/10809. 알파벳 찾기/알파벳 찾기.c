#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i, num;
    char alp;
	char word[100];
	scanf("%s", word);

    for(alp = 'a'; alp<='z'; alp++)
    {
		i=0; num=-1;
		while(word[i]!='\0')
		{
            if(word[i]==alp)
            {
				num=i;
                break;
            }
			i++;
        }
		printf("%d ", num);
    }
    return 0;
}