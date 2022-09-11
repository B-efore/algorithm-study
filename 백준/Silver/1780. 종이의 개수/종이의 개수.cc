#include <stdio.h>
#define N 2187
// 각각 -1, 0, 1 로만 채워진 종이의 개수
int n, s1, s2, s3;
int p[N + 1][N + 1];
void solve(int y, int x, int size);
int main(void)
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &p[i][j]);
	
	solve(1, 1, n);

	printf("%d\n%d\n%d\n", s1, s2, s3);
	return 0;
}

void solve(int y, int x, int size)
{
	int tmp = p[y][x];
	int check = 1;

	for (int i = y; i < size + y; i++) {
		for (int j = x; j < size + x; j++) {
			if (p[i][j] != tmp) {
				check = 0;
				break;
			}
		}
	}

	// 종이가 모두 같은 수인 경우
	if (check) {
		if (tmp == -1) s1++;
		else if (tmp == 0) s2++;
		else s3++;
	}
	// 아닌 경우 9개로 자르고 반복
	else {
		size /= 3;

		solve(y, x, size);
		solve(y, x + size, size);
		solve(y, x + 2 * size, size);

		solve(y + size, x, size);
		solve(y + size, x + size, size);
		solve(y + size, x + 2 * size, size);

		solve(y + 2 * size, x, size);
		solve(y + 2 * size, x + size, size);
		solve(y + 2 * size, x + 2 * size, size);
	}
}