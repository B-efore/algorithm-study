#include <stdio.h>
#define INF	987654321
#define N	401
int main(void)
{
	int k, i, j, n, e, c;
	int v[N][N];
	scanf("%d %d", &n, &e);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			v[i][j] = INF;

	for (k = 1; k <= e; k++)
	{
		scanf("%d %d %d", &i, &j, &c);
		v[i][j] = c;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (v[i][j] > v[i][k] + v[k][j])
					v[i][j] = v[i][k] + v[k][j];

	k = 1;
	for (i = 1; i <= n; i++) {
		if (v[k][k] > v[i][i])
			k = i;
	}

	if (v[k][k] != INF)
		printf("%d\n", v[k][k]);
	else
		printf("-1\n");

	return 0;
}