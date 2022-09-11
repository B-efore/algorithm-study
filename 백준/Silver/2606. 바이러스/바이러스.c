#include <stdio.h>
int graph[101][101];
int BFSvisit[101], queue[101];

int BFS(int v, int n)
{
    int w, front, rear, pop;
    int num=0;
	front = rear = 0;
    queue[0] = v;
    BFSvisit[v] = 1;
    rear++;

    while(front<rear)
    {
        pop = queue[front];
        front++;

        for(w=1; w<=n; w++)
        {
            if (graph[pop][w] == 1 && BFSvisit[w] == 0)
            {
                queue[rear] = w;
                rear++;
                BFSvisit[w]=1;
				num++;
            }
        }
    }
	return num;
}

int main(void)
{
	int i, n, t, a, b;
	scanf("%d", &n);
	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b]=graph[b][a]=1;
	}

	t=BFS(1, n);
	printf("%d\n", t);
	return 0;
}