#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
	int data;
	struct _node * next;
	struct _node * prev;
} Node;
typedef struct _list
{
	Node * head;
	Node * tail;
	int num;
} List;
void ListInit(List * list)
{
	list->head = NULL;
	list->tail = NULL;
	list->num = 0;
}
void push_front(List * list, int num)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = num;

	if(list->num==0)
	{
		list->head = newNode;
		list->tail = newNode;
	}

	newNode->prev=NULL;

	if(list->head==NULL)
	{
		newNode->next = NULL;
	}
	else
	{
		newNode->next = list->head;
		list->head->prev = newNode;
	}

	list->head = newNode;
	list->num++;
}
void push_back(List * list, int num)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = num;

	if(list->num==0)
	{
		list->head = newNode;
		list->tail = newNode;
	}

	newNode->next = NULL;

	if (list->tail == NULL)
	{
		newNode->prev = NULL;
	}
	else
	{
		newNode->prev = list->tail;
		list->tail->next = newNode;
	}

	list->tail = newNode;
	list->num++;
}
void pop_front(List * list)
{
	Node * tmp = list->head;

	if(list->head==NULL)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", tmp->data);
		list->head = tmp->next;
		list->num--;
		free(tmp);

		if(list->num==0)
		{
			list->head = NULL;
			list->tail = NULL;
		}
	}
}
void pop_back(List * list)
{
	Node * tmp = list->tail;

	if(list->tail==NULL)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", tmp->data);
		list->tail = list->tail->prev;
		list->num--;
		free(tmp);

		if(list->num==0)
		{
			list->head = NULL;
			list->tail = NULL;
		}
	}
}
void size(List * list)
{
	printf("%d\n", list->num);
}
void empty(List * list)
{
	if(list->num==0)
		printf("1\n");
	else
		printf("0\n");
}
void front(List * list)
{
	if(list->num!=0)
		printf("%d\n", list->head->data);
	else
		printf("-1\n");
}
void back(List * list)
{
	if(list->num!=0)
		printf("%d\n", list->tail->data);
	else
		printf("-1\n");
}
int main(void)
{
	int i, n, tmp;
	char check[15];

	scanf("%d", &n);

	List q;
	ListInit(&q);

	for(i=0; i<n; i++)
	{
		scanf("%s", check);	

		if (!strcmp(check, "push_front"))
		{
			scanf("%d", &tmp);
			push_front(&q, tmp);
		}
		else if (!strcmp(check, "push_back"))
		{
			scanf("%d", &tmp);
			push_back(&q, tmp);
		}
		else if (!strcmp(check, "pop_front"))
			pop_front(&q);
		else if (!strcmp(check, "pop_back"))
			pop_back(&q);
		else if (!strcmp(check, "size"))
			size(&q);
		else if (!strcmp(check, "empty"))
			empty(&q);
		else if (!strcmp(check, "front"))
			front(&q);
		else if (!strcmp(check, "back"))
			back(&q);
	}

	return 0;
}
