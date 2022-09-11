#include <stdio.h>
#include <string.h>
int main(void)
{
	char tmp;
	char num1[4], num2[4];

	scanf("%3s%3s", num1, num2);

	tmp = num1[2];
	num1[2] = num1[0];
	num1[0] = tmp;

	tmp = num2[2];
	num2[2] = num2[0];
	num2[0] = tmp;

	if (strcmp(num1, num2)>0)
		printf("%s\n", num1);
	else
		printf("%s\n", num2);
	return 0;
}