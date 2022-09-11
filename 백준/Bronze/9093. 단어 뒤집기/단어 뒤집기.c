#include <stdio.h>
#include <string.h>
void reverse(char arr[], int len);
int main(void)
{
	int t, len;
	char s[1001];
	scanf("%d", &t);
	getchar();

	while (t--)
	{
		fgets(s, 1000, stdin);

		len = strlen(s)-1;
		s[len] = 0;

		reverse(s, len);
	}
}
void reverse(char arr[], int len)
{
	int i, j, k;

	i = 0;

	while(i<len)
	{
		j = 0;

		if ((arr[i] == ' ') || (i==0))
		{
			if(i!=0)
				printf(" ", arr[i++]);

			while (arr[i] != ' ' && i < len)
			{
				i++; j++;
			}
		}

		k = 1;

		while (j--)
		{
			printf("%c", arr[i - k]);
			k++;
		}
	}
	printf("\n");
}