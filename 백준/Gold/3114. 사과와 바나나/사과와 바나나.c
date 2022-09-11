#include <stdio.h>
#include <stdbool.h>
#define R 1500
#define C 1500

bool tree[R+1][C+1];
int number[R+1][C+1];
int aSum[R+1][C+1];
int bSum[R+1][C+1];
int sum[R+1][C+1];
int r, c;

int v(int, int, int);
int main(void){

	int i, j, num;
	char tmp;
	scanf("%d %d", &r, &c);

	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			getchar();
			scanf("%c%d", &tmp, &num);

			if(tmp=='A'){
				tree[i][j] = true;
				number[i][j] = num;
			}
			else if(tmp=='B'){
				tree[i][j] = false;
				number[i][j] = num;
			}
		}
	}

	//사과, 바나나 누적합 구하기
	for(j=1; j<=c; j++){
		for(i=r; i>=1; i--){
			if(tree[i][j]){
				if(i!=r){
					aSum[i][j] = aSum[i+1][j] + number[i][j];
					bSum[i][j] = bSum[i+1][j];
				}
				else{
					aSum[i][j] = number[i][j];
					bSum[i][j] = 0;
				}
			}
			else{
				if(i!=r){
					aSum[i][j] = aSum[i+1][j];
					bSum[i][j] = bSum[i+1][j] + number[i][j];
				}
				else{
					aSum[i][j] = 0;
					bSum[i][j] = number[i][j];
				}
			}
		}
	}

	sum[1][1] = aSum[2][1];
	//1행 구하기
	for(j=2; j<=c; j++)
		sum[1][j] = sum[1][j-1] + aSum[2][j];

	//1열 구하기
	for(i=2; i<=r; i++){
		if(tree[i][1])
			sum[i][1] = aSum[i][1]-number[i][1];
		else
			sum[i][1] = aSum[i][1];
	}

	int t1, t2, t3;

	for(i=2; i<=r; i++){
		for(j=2; j<=c; j++){
			t1 = sum[i-1][j] + v(i, j, 0);
			t2 = sum[i-1][j-1] + v(i, j, 1);
			t3 = sum[i][j-1] + v(i, j, 2);

			if(t1>=t2&&t1>=t3)
				sum[i][j] = t1;
			else if(t2>=t1&&t2>=t3)
				sum[i][j] = t2;
			else
				sum[i][j] = t3;
		}
	}

	printf("%d\n", sum[r][c]);
	return 0;
}
int v(int i, int j, int m)
{
	int tmp=0;

	//위에서 아래로
	if(m==0){
		if(tree[i][j])
			tmp = -number[i][j];	
	}
	else if(m==1){ //대각선으로
		tmp = aSum[i+1][j] + bSum[1][j] - bSum[i][j];
	}
	else if(m==2){ //왼쪽에서 오른쪽으로
		tmp = aSum[i+1][j] + bSum[1][j] - bSum[i][j];
	}

	return tmp;
}
