#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	return strcmp((char*)a, (char*)b);
}
int main(void)
{
	int i, j, k, len;
	char word[1001];
	char suffix[1001][1001] = { 0 };

	scanf("%s", word);
	len = strlen(word);

	for (i = 0; i < len; i++)
		strcpy(suffix[i], word+i);

	qsort(suffix, len, sizeof(suffix[0]), compare);

	for (i = 0; i < len; i++)
		printf("%s\n", suffix[i]);
    
	return 0;
}