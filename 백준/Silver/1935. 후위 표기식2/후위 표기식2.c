#include <stdio.h>
#include <string.h>
#define N 26

int idx = 0;
double stack[N];

void push(double stack[], double n)
{
	stack[idx] = n;
	idx++;
}

double pop(double stack[])
{
	double tmp;

	if (idx > 0)
	{
		idx--;
		tmp = stack[idx];
		stack[idx] = 0;
	}
	return tmp;
}

int main(void)
{
	int i, n, tmp;
	double op1, op2, alp[N];
	char arr[2 * N];

	scanf("%d", &n);
	scanf("%s", arr);

	for (i = 0; i < n; i++)
		scanf("%lf", &alp[i]);

	for (i = 0; i < strlen(arr); i++)
	{
		tmp = arr[i];

		if (tmp >= 'A' && tmp <= 'Z')
		{
			push(stack, alp[tmp - 'A']);
		}
		else
		{
			op2 = pop(stack);
			op1 = pop(stack);

			switch (tmp)
			{
			case '+':
				push(stack, op1 + op2);
				break;
			case '-':
				push(stack, op1 - op2);
				break;
			case '*':
				push(stack, op1 * op2);
				break;
			case '/':
				push(stack, op1 / op2);
				break;
			}
		}
	}

	printf("%.2lf", pop(stack));
	return 0;
}