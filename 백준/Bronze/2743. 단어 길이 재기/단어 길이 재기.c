#include <stdio.h>
#include <string.h>
int main(void)
{
	int len;
	char word[101];

	scanf("%s", word);
	len = strlen(word);

	printf("%d\n", len);
	return 0;
}