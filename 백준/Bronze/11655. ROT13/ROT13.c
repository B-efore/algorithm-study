#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, len;
	char word[101];
	gets(word);

	len = strlen(word);
	
	for (i = 0; i < len; i++)
	{
		if ((word[i] >= 'a') && (word[i] <= 'm'))
			printf("%c", word[i] + 13);
		else if ((word[i] >= 'n') && (word[i] <= 'z'))
			printf("%c", word[i] - 13);
		else if ((word[i] >= 'A') && (word[i] <= 'M'))
			printf("%c", word[i] + 13);
		else if ((word[i] >= 'N') && (word[i] <= 'Z'))
			printf("%c", word[i] - 13);
		else
			printf("%c", word[i]);
	}
	printf("\n");
	return 0;
}