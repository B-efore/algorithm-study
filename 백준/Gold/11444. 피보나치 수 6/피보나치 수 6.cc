#include <stdio.h>
#include <cstring>
#include <algorithm>
#define N 2
#define DIV 1000000007

long long matrix[N + 1][N + 1];
long long result[N + 1][N + 1], m1[N + 1][N + 1], m2[N + 1][N + 1];
long long n;

void mul(long long m1[N + 1][N + 1], long long m2[N + 1][N + 1]);
void solve(long long m, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1]);

int main(void)
{
	scanf("%lld", &n);

	matrix[0][0] = 1; matrix[0][1] = 1;
	matrix[1][0] = 1; matrix[1][1] = 0;

	if (n > 1) {
		solve(n - 1, m1, m2);
		printf("%lld\n", result[0][0] % DIV);
	}
	else
		printf("%lld\n", matrix[1][1-n]);

	return 0;
}

void mul(long long m1[N + 1][N + 1], long long m2[N + 1][N + 1])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result[i][j] = 0;

			for (int k = 0; k < N; k++)
				result[i][j] += (m1[i][k] * m2[k][j]);

			result[i][j] %= DIV;
		}
	}
}

void solve(long long m, long long m1[N + 1][N + 1], long long m2[N + 1][N + 1])
{
	if (m == 1) {
		memcpy(result, matrix, sizeof(matrix));
	}
	// n이 짝수인 경우
	else if (m % 2 == 0) {
		solve(m / 2, m1, m2);
		mul(m1, m2);
	}
	// n이 홀수인 경우
	else if (m % 2 == 1) {
		solve(m - 1, m1, m2);
		mul(matrix, m1);
	}

	memcpy(m1, result, sizeof(result));
	memcpy(m2, result, sizeof(result));
}