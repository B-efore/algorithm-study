#include <stdio.h>
#include <string.h>

int main(void)
{
	int num=0, sum=0;
	char stick[100001];
	scanf("%s", stick);

	for (int i = 0; i < strlen(stick); i++)
	{
		if (stick[i] == '(')
		{
			if (stick[i + 1] == ')')
			{
				sum += num;
				i++;
			}
			else
				num++;
		}
		else
		{
			sum++;
			num--;
		}
	}

	printf("%d\n", sum);
	return 0;
}