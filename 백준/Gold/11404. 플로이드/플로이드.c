#include <stdio.h>
#define INF 987654321
int main(void)
{
	int i, n, m, a, b, c;
	int v[101][101] = { 0 };
	int check[101][101] = { 0 };
	scanf("%d %d", &n, &m);

	//초기화
	for (a = 1; a <= n; a++)
		for (b = 1; b <= n; b++)
				v[a][b] = INF;

	for (i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		
		if (v[a][b] > c)
			v[a][b] = c;
	}

	for (a = 1; a <= n; a++){
		for (b = 1; b <= n; b++){
			for (c = 1; c <= n; c++){
					if (v[b][c] > v[b][a] + v[a][c])
						v[b][c] = v[b][a] + v[a][c];
			}
		}
	}

	for (a = 1; a <= n; a++){
		for (b = 1; b <= n; b++) {
			if (v[a][b] == INF || a==b)
				printf("0 ");
			else
				printf("%d ", v[a][b]);
		}
		printf("\n");
	}

	return 0;
}