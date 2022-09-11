#include <stdio.h>
#define N 102
typedef struct point
{
	int x;
	int y;
	int visit;
} Point;
void bfs(Point v[], int index, int n);
int dis(Point a, Point b);
int abs(int a, int b);
int main(void)
{
	Point v[N];
	int i, j, t, n;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		
		for (j = 0; j < n + 2; j++)
		{
			scanf("%d %d", &v[j].x, &v[j].y);
			v[j].visit = 0;
		}

		bfs(v, 0, n);

		if (v[n+1].visit != 1)
			printf("sad\n");
		else
			printf("happy\n");
	}
}
void bfs(Point v[], int index, int n)
{
	v[index].visit = 1;
	for (int i = 0; i < n + 2; i++)
	{
		if (v[i].visit == 0 && dis(v[i], v[index]) <= 1000)
			bfs(v, i, n);
	}
}
int dis(Point a, Point b)
{
	return abs(a.x, b.x) + abs(a.y, b.y);
}
int abs(int a, int b)
{
	return a > b ? a - b: b - a;
}