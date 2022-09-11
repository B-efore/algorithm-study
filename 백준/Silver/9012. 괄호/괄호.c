#include <stdio.h>
#include <string.h>
int idx=0;
void push(char stack[], char n)
{
	stack[idx]=n;
	idx++;
}
int pop(char stack[])
{
	int num;

	if (idx>0)
	{
		idx--;
		num = stack[idx];
		stack[idx]=0;
	}
	else
		num = -1;

	return num;
}
int size()
{
	return idx;
}
int empty()
{
	if (idx==0)
		return 1;
	else
		return 0;
}
char top(char stack[])
{
	char num;


	if(idx>0)
		num = stack[idx-1];
	else
		num = -1;

	return num;
}
int main(void)
{
	int i, t, l, len;
	char arr[50];
	char stack[50];
	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%s", arr);
		len = strlen(arr); l=0;

		while(l<len)
		{
			if(arr[l]==')')
			{
				if(stack[size()-1]=='(')
					pop(stack);
				else
					push(stack, arr[l]);
			}
			else
				push(stack, arr[l]);

			l++;
		}

		if(empty())
			printf("YES\n");
		else
			printf("NO\n");

		while(!empty())
			pop(stack);
	}
    
	return 0;
}