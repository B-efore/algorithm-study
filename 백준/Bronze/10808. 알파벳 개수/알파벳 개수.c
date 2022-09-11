#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, num[26] = { 0 };
	char tmp, word[100];

	scanf("%s", word);
	l = strlen(word);

	for (i = 0; i < l; i++)
	{
		tmp = word[i];
		num[tmp - 97]++;
	}

	for (i = 0; i < 26; i++)
		printf("%d ", num[i]);
	printf("\n");

	return 0;
}