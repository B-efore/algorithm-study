#include <stdio.h>
int graph[1001][1001];
int DFSvisit[1001];
int BFSvisit[1001];
int queue[1001];
void DFS(int, int);
void BFS(int, int);
int main(void)
{
	int n, m, v, x, y, i;
	scanf("%d %d %d", &n, &m, &v);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(v, n);
	printf("\n");
	BFS(v, n);
	printf("\n");

	return 0;
}
void DFS(int v, int n)
{
	printf("%d ", v);
	DFSvisit[v] = 1;

	for (int i = 0; i <= n; i++)
	{
		if (graph[v][i] == 1 && DFSvisit[i] == 0)
			DFS(i, n);
	}
}
void BFS(int v, int n)
{
	printf("%d ", v);

	int front, rear, pop, i;
	front = rear = 0;
	queue[0] = v;
	BFSvisit[v] = 1;
	rear++;

	while (front < rear)
	{
		pop = queue[front++];

		for (i = 1; i <= n; i++)
		{
			if (graph[pop][i] == 1 && BFSvisit[i] == 0)
			{
				printf("%d ", i);
				queue[rear++] = i;
				BFSvisit[i] = 1;
			}
		}
	}
}