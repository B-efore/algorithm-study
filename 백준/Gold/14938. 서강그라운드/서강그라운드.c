#include <stdio.h>
#define INF 987654321
int main(void)
{
	int k, i, j, l, n, m, r, sum1, sum2=0;
	int item[101];
	int v[101][101];
	scanf("%d %d %d", &n, &m, &r);

	for (i = 1; i <= n; i++)
		scanf("%d", &item[i]);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			v[i][j] = INF;

	for (k = 1; k <= r; k++)
	{
		scanf("%d %d %d", &i, &j, &l);
		v[i][j] = l;
		v[j][i] = l;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];

	for (i = 1; i <= n; i++) {

		sum1 = 0;
		for (j = 1; j <= n; j++)
			if (v[i][j] <= m || i == j)
				sum1 += item[j];

		if (sum1 > sum2)
			sum2 = sum1;
	}

	printf("%d\n", sum2);
	return 0;
}