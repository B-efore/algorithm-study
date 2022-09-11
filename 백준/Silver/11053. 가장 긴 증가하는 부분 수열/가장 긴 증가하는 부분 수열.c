#include <stdio.h>
#define N 1000
int L[N + 1];
int num[N + 1];
int main(void)
{
	int i, j, tmp, max = 0, n;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for (i = 1; i <= n; i++) {

		tmp = 0;

		for (j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				tmp = Max(tmp, L[j]);
			}
		}

		L[i] = ++tmp;

		if (max < L[i])
			max = L[i];
	}

	printf("%d\n", max);
	return 0;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}