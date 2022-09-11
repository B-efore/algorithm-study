#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, len, num[4];
	char word[102];
	
	while (fgets(word, sizeof(word), stdin)!=NULL)
	{
		len = strlen(word);

		for (i = 0; i < 4; i++)
			num[i] = 0;

		for (i = 0; i < len; i++)
		{
			if (word[i] == ' ')
				num[3]++;
			else if ((word[i] >= 65) && (word[i] <= 90))
				num[1]++;
			else if ((word[i] >= 97) && (word[i] <= 122))
				num[0]++;
			else if ((word[i] >= 48) && (word[i] <= 57))
				num[2]++;
		}

		for (i = 0; i < 4; i++)
			printf("%d ", num[i]);
		printf("\n");
	}
	return 0;
}