#include <stdio.h>
#include <string.h>

int idx = 0;
char stack[100];

void push(double n)
{
	stack[idx] = n;
	idx++;
}

char pop()
{
	char tmp;

	if (idx > 0)
	{
		idx--;
		tmp = stack[idx];
		stack[idx] = 0;
	}
	else
		tmp = 0;

	return tmp;
}

char top()
{
	char tmp;

	if (idx > 0)
		tmp = stack[idx - 1];
	else
		tmp = 0;

	return tmp;
}

int main(void)
{
	char tmp, c;
	char arr[101];
	scanf("%s", arr);

	for (int i = 0; i < strlen(arr); i++)
	{
		tmp = arr[i];

		if ((tmp >= 'A') && (tmp <= 'Z'))
			printf("%c", tmp);
		else
		{
			switch (tmp)
			{
			case '(':
				push(tmp);
				break;
			case ')':
				while ((c = pop()) != '(')
					printf("%c", c);
				break;
			case '+':
			case '-':
				while (top() != '(' && idx > 0)
					printf("%c", pop());
				push(tmp);
				break;
			case '*':
			case '/':
				while ((idx > 0) && (top() == '*' || top() == '/'))
					printf("%c", pop());
				push(tmp);
				break;
			}
		}
	}

		while (idx != 0)
			printf("%c", pop(stack));

		return 0;
}