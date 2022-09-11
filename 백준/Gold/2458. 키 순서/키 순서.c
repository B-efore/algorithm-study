#include <stdio.h>
#define INF	987654321
#define N	501
int main(void)
{
	int k, i, j, n, m, s, num=0;
	int v[N][N];
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			v[i][j] = INF;

	for (k = 1; k <= m; k++)
	{
		scanf("%d %d", &i, &j);
		v[i][j] = 1;
		v[j][i] = -1;
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (v[i][k] == 1 && v[k][j] == 1) {
					v[i][j] = 1;
					v[j][i] = -1;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {

		k = 0;
		for (j = 1; j <= n; j++)
		{
			if (v[i][j] != INF || i == j)
				continue;
			else
			{
				k++;
				break;
			}
		}

		if (k == 0)
			num++;
	}

	printf("%d\n", num);
	return 0;
}