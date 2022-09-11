#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int i, k, tmp, sum=0;
	scanf("%d", &k);

	int * stack = (int *)malloc(sizeof(int)*k);
	for(i=0; i<k; i++)
	{
		scanf("%d", &tmp);

		if(tmp==0)
			pop(stack);
		else
			push(stack, tmp);
	}

	while(!empty())
		sum+=pop(stack);

	printf("%d\n", sum);
	return 0;
}