#include <stdio.h>
#define N	401
int main(void)
{
	int k, i, j, n, e, s;
	int v[N][N] = { 0 };
	scanf("%d %d", &n, &e);

	for (k = 1; k <= e; k++)
	{
		scanf("%d %d", &i, &j);
		v[i][j] = -1;
		v[j][i] = 1;
	}

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (v[i][k] == -1 && v[k][j] == -1) {
					v[i][j] = -1;
					v[j][i] = 1;
				}
			}
		}
	}

	scanf("%d", &s);

	for (k = 1; k <= s; k++)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", v[i][j]);
	}

	return 0;
}