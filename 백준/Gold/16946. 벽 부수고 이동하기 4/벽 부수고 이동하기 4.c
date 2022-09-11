#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 1000
#define M 1000

typedef struct Data{
	int x;
	int y;
} Data;

typedef struct Node{
	Data data;
	struct Node *next;
} Node;

typedef struct Queue{
	Node *front;
	Node *rear;
} Queue;

Queue q;

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int map[N+1][M+1];
int group[N+1][M+1];
int groupCnt[N*M+1];

int bfs(int, int, int);
bool isEmpty(Queue *);
void QueueInit(Queue *);
void Enqueue(Queue *, Data);
Data Dequeue(Queue *);

int main(void)
{
	int i, j, idx;
	scanf("%d %d", &n, &m);
	
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			scanf("%1d", &map[i][j]);

	QueueInit(&q);
	idx = 1;

	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(!map[i][j] && !group[i][j]){
				groupCnt[idx] = bfs(i, j, idx);
				idx++;
			}
		}
	}

	/*
	printf("\ngroup\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++)
			printf("%d ", group[i][j]);
		printf("\n");
	}

	printf("\ngroupCnt\n");
	for(i=1; groupCnt[i]!=0; i++)
		printf("%d ", groupCnt[i]);
	*/

	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			if(map[i][j]==1){
				
				int tmp_num[4];
				int x, y;
				bool check;

				for(int k=0; k<4; k++){

					y = i + dy[k];
					x = j + dx[k];

					tmp_num[k] = 0;

					if(x<1 || x>m || y<1 || y>n)
						continue;

					tmp_num[k] = group[y][x];
					check = true;

					for(int l=0; l<k; l++){
						if(tmp_num[k]==tmp_num[l]){
							check = false;
							break;
						}
					}

					if(check)
						map[i][j] += groupCnt[tmp_num[k]];
				}
			}
		}
	}

	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++)
			printf("%d", map[i][j]%10);
		printf("\n");
	}

	return 0;
}
int bfs(int s_y, int s_x, int idx)
{
	Data cur;
	Data tmp;

	int count = 1;
	group[s_y][s_x] = idx;

	tmp.y = s_y;
	tmp.x = s_x;
	Enqueue(&q, tmp);

	while(!isEmpty(&q))
	{
		cur = Dequeue(&q);

		for(int i=0; i<4; i++)
		{
			int y = cur.y + dy[i];
			int x = cur.x + dx[i];

			if(x<1 || x>m || y<1 || y>n)
				continue;

			if(map[y][x] == 0 && group[y][x] == 0)
			{
				count++;
				group[y][x] = idx;
				tmp.x = x;
				tmp.y = y;
				
				Enqueue(&q, tmp);
			}
		}
	}

	return count;
}
void QueueInit(Queue *queue)
{
	queue -> front = NULL;
	queue -> rear = NULL;
}
void Enqueue(Queue *queue, Data data)
{
	Node * newNode = (Node *)malloc(sizeof(Node));

	newNode -> data = data;
	newNode -> next = NULL;

	if(queue -> front == NULL)
		queue -> front = newNode;
	else
		queue -> rear -> next = newNode;

	queue -> rear = newNode;
}
Data Dequeue(Queue *queue)
{
	if(!isEmpty(queue))
	{
		Node *tmpNode = queue -> front;
		Data data = tmpNode -> data;

		if(tmpNode == queue -> rear)
		{
			queue -> front = NULL;
			queue -> rear = NULL;
		}
		else
			queue -> front = tmpNode -> next;

		free(tmpNode);
		return data;
	}
}
bool isEmpty(Queue *queue)
{
	return (queue -> front == NULL);
}