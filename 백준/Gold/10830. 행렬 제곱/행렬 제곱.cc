#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5
#define DIV 1000

long long matrix[N + 1][N + 1];
long long tmp_m[N + 1][N + 1];
long long m1[N + 1][N + 1];
long long m2[N + 1][N + 1];

void mul(int n, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1]);
void solve(int n, long long b, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1]);

int main(void)
{
	int n, t;
	long long b;
	scanf("%d %lld", &n, &b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			matrix[i][j] = t % DIV;
		}
	}

	solve(n, b, m1, m2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", tmp_m[i][j]);
		}
		printf("\n");
	}

}

void mul(int n, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			tmp_m[i][j] = 0;

			for (int k = 0; k < n; k++) {
				tmp_m[i][j] += (m1[i][k] * m2[k][j]);
			}

			tmp_m[i][j] %= DIV;
		}
	}
}

void solve(int n, long long b, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1])
{
	if (b == 1) {
		memcpy(tmp_m, matrix, sizeof(matrix));
	}
	else if (b % 2 == 1) {
		solve(n, b - 1, m1, m2);
		mul(n, matrix, m1);
	}
	else if (b % 2 == 0) {
		solve(n, b / 2, m1, m2);
		mul(n, m1, m2);
	}

	memcpy(m1, tmp_m, sizeof(tmp_m));
	memcpy(m2, tmp_m, sizeof(tmp_m));
}