#include <stdio.h>
#include <string.h>
void reverse(char arr[], int len);
int main(void)
{
	int len;
	char s[100002];

	fgets(s, 100002, stdin);

	len = strlen(s) - 1;
	s[len] = 0;

	reverse(s, len);
	return 0;
}
void reverse(char arr[], int len)
{
	int i, j, k;

	i = 0;

	while (i < len)
	{
		j = 0;

		if (arr[i] == '<')
		{
			while (arr[i] != '>')
			{
				printf("%c", arr[i]);
				i++;
			}
			printf("%c", arr[i++]);
			continue;		
		}

		if ((arr[i] == ' ') || (arr[i-1] == '>') ||(i == 0))
		{
			if (arr[i] == ' ')
			{
				printf(" ");
				i++;
			}

			while ((arr[i] != ' ')&&(arr[i] != '<') && i < len)
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