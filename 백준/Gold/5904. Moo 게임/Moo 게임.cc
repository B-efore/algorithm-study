#include <stdio.h>
#include <stdlib.h>
void solve(int, int, int);
int main(void)
{
	int n;
	scanf("%d", &n);

	solve(n, 0, 0);

	return 0;
}

void solve(int n, int k, int cnt)
{
	int len = 2 * cnt + k + 3;

	// 수열 S(k)에 n이 존재하는 경우
	if(n<=len){
		// L(k-1) + 1 의 경우 m
		if(n == cnt+1){
			printf("m\n");
            exit(0);
		}
		// 중간 파트에서 나머지는 o
		else if((n > cnt+1) && (n <= cnt+k+3)){
			printf("o\n");
            exit(0);
		}
		// 마지막 L(k-1)의 파트
		else{
			solve(n-cnt-k-3, 0, 0);
		}
	}
	// 수열 S(k)에 n이 존재하지 않는 경우
	else
		solve(n, k+1, len);
}