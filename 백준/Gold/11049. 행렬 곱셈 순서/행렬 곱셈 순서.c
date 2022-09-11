#include <stdio.h>
#define N 500
#define INF 1987654321

typedef struct matrix{
	int row;
	int column;
} Matrix;

Matrix matrix[N+1];
// i 부터 j 까지 행렬 곱셈의 최소
int sum[N+1][N+1];
int main(void)
{
	int i, j, k, diagonal, n, r, c;
	scanf("%d", &n);

	for(i=1; i<=n; i++){
		scanf("%d %d", &r, &c);
	
		matrix[i].row = r;
		matrix[i].column = c;
	}

	int tmp, min;

	for(diagonal=1; diagonal<=n-1; diagonal++){
		for(i=1; i<=n-diagonal; i++){

			j = i + diagonal;
			min = INF;

			for(k=i; k<j; k++){
				tmp = sum[i][k] + sum[k+1][j] + (matrix[i].row * matrix[k].column * matrix[j].column);
				
				if(tmp<min)
					min = tmp;
			}

			sum[i][j] = min;
		}
	}

	printf("%d\n", sum[1][n]);
	return 0;
}