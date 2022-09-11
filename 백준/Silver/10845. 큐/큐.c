#include <stdio.h>
#include <string.h>
typedef struct queue
{
	int data[10001];
	int front;
	int back;
} Queue;
void push(Queue * q, int num)
{
	q -> data[q->back++] = num;
}
int pop(Queue * q)
{
	int num;

	if(q->data[q->front]!=0)
	{
		num = q->data[q->front];
		q->data[q->front++]=0;
		return num;
	}
	else
	{
		return -1;
	}
}
int size(Queue * q)
{
	int sum = q->back - q->front;
	return sum;
}
int empty(Queue * q)
{
	if(size(q)==0)
		return 1;
	else
		return 0;
}
int front(Queue * q)
{
	if (empty(q))
		return -1;
	else
		return q->data[q->front];

}
int back(Queue * q)
{
	if (empty(q))
		return -1;
	else
		return q->data[q->back-1];
}
int main(void)
{
	int i, n, tmp;
	char check[10];
	
	Queue q;
	q.front = 1;
	q.back = 1;

	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		scanf("%s", check);

		if (!strcmp(check, "pop"))
			printf("%d\n", pop(&q));
		else if (!strcmp(check, "size"))
			printf("%d\n", size(&q));
		else if (!strcmp(check, "empty"))
			printf("%d\n", empty(&q));
		else if (!strcmp(check, "front"))
			printf("%d\n", front(&q));
		else if (!strcmp(check, "back"))
			printf("%d\n", back(&q));
		else if (!strcmp(check, "push"))
		{
			scanf("%d", &tmp);
			push(&q, tmp);
		}
	}
	return 0;
}