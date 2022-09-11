#include <stdio.h>
#define INF 987654321
int main(void)
{
	int k, i, j, n, m, sum1, sum2 = INF;
	int v[101][101];
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			v[i][j] = INF;

	for (k = 0; k < m; k++)
	{
		scanf("%d %d", &i, &j);
		v[i][j] = 1;
		v[j][i] = 1;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];

	for (i = 1; i <= n; i++) {

		sum1 = 0;
		for (j = 1; j <= n; j++) {
			if (j != i)
				sum1 += v[i][j];
		}

		if (sum1 < sum2)
		{
			k = i;
			sum2 = sum1;
		}
	}

	printf("%d\n", k);
	return 0;
}