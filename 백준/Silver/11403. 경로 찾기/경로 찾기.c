#include <stdio.h>
#define INF 987654321
int main(void)
{
	int k, i, j, n;
	int v[101][101];
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &v[i][j]);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if(v[i][j]==0)
				v[i][j] = INF;

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (v[i][j] < INF)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}