#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int idx=0;
void push(int stack[], int n)
{
	stack[idx]=n;
	idx++;
}
int pop(int stack[])
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
int top(int stack[])
{
	int num;


	if(idx>0)
		num = stack[idx-1];
	else
		num = -1;

	return num;
}
int main(void)
{
	int n, i, tmp;
	char check[10];

	scanf("%d", &n);
	getchar();
	
	int * stack = (int *)malloc(sizeof(int)*n);

	for(i=0; i<n; i++)
	{
		scanf("%s",check);

		if (!strcmp(check, "top"))
			printf("%d\n", top(stack));
		else if (!strcmp(check, "empty"))
			printf("%d\n", empty());
		else if (!strcmp(check, "size"))
			printf("%d\n", size());
		else if (!strcmp(check, "pop"))
			printf("%d\n", pop(stack));
		else if (!strcmp(check, "push"))
		{
			scanf("%d", &tmp);
			push(stack, tmp);
		}
	}
    
    free(stack);
	return 0;
}