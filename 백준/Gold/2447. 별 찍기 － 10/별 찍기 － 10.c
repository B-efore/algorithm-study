#include <stdio.h>
# define N 2187
int arr[N + 1][N + 1];
void setStar(int, int, int);
int main(void)
{
	int n;
	scanf("%d", &n);

	setStar(n, 1, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == '*')
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
}
void setStar(int n, int y, int x)
{
	if (n == 3) {

		for (int i = x; i < x + 3; i++)
			arr[y][i] = '*';
		
		arr[y + 1][x] = '*'; arr[y + 1][x + 2] = ' '; arr[y + 1][x + 2] = '*';

		for (int i = x; i < x + 3; i++)
			arr[y + 2][i] = '*';
	}

	else {

		n /= 3;

		setStar(n, y, x);
		setStar(n, y, x + n);
		setStar(n, y, x + 2 * n);

		setStar(n, y + n, x);
//		setStar(n, y + n, x + n);
		setStar(n, y + n, x + 2 * n);

		setStar(n, y + 2 * n, x);
		setStar(n, y + 2 * n, x + n);
		setStar(n, y + 2 * n, x + 2 * n);


	}
}