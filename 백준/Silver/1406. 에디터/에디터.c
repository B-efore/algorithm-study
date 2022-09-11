#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char word;
	struct node* prev;
	struct node* next;
} Node;

typedef struct list
{
	Node* head;
	Node* cursor;
} List;

void ListInit(List* list);
void PrintList(List list, Node* dummy);
void AddNode(List* list, char tmp);
char RNode(List* list);

int main(void)
{
	int i, m;
	char ins, tmp;

	List list;
	ListInit(&list);

	Node* dummy = (Node*)malloc(sizeof(Node));
	dummy->prev = NULL;
	list.cursor = dummy;

	while ((tmp = getchar()) != '\n')
		AddNode(&list, tmp);

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		while (getchar() != '\n');

		scanf("%c", &ins);

		if (ins == 'L')
		{
			if (list.cursor!=list.head)
				list.cursor = list.cursor->prev;
		}
		else if (ins == 'D')
		{
			if (list.cursor != dummy)
				list.cursor = list.cursor->next;
		}
		else if (ins == 'B')
		{
			RNode(&list);
		}
		else if (ins == 'P')
		{
			getchar();
			scanf("%c", &tmp);
			AddNode(&list, tmp);
		}
	}

	PrintList(list, dummy);
	return 0;
}
void PrintList(List list, Node * dummy)
{
	char tmp;

	list.cursor = list.head;
	while ((list.cursor) != dummy)
	{
		tmp = list.cursor->word;
		printf("%c", tmp);
		list.cursor = list.cursor->next;
	}
	printf("\n");
}
void ListInit(List* list)
{
	list->head = NULL;
	list->cursor = NULL;
}
void AddNode(List* list, char tmp)
{
	Node* newnode = (Node*)malloc(sizeof(Node));

	//맨 앞에 추가하는 경우
	if (list->cursor->prev == NULL)
		list->head = newnode;

	newnode->word = tmp;
	newnode->prev = list->cursor->prev;
	newnode->next = list->cursor;

	//맨 앞에 추가하지 않는 경우
	if(list->cursor->prev!=NULL)
		list->cursor->prev->next = newnode;
	list->cursor->prev = newnode;
}
char RNode(List* list)
{
	if (list->cursor != list->head)
	{
		Node* tmpNode = list->cursor->prev;
		char t = tmpNode->word;

		if (tmpNode->prev != NULL)
		{
			tmpNode->prev->next = list->cursor;
			list->cursor->prev = tmpNode->prev;
		}
		else
		{
			list->cursor->prev = NULL;
			list->head = list->cursor;
		}

		free(tmpNode);
		return t;
	}
	return 0;
}