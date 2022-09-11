#include <stdio.h>
#include <string.h>
#define N 20
#define M 10000
int money[N+1];
int s[M+1];
void solve(int, int);
int main(void)
{
	int t, n, m;
	scanf("%d", &t);

	for(int c=1; c<=t; c++){

		memset(money, 0, sizeof(money));
		memset(s, 0, sizeof(s));

		//동전의 가지수 입력
		scanf("%d", &n);
		
		//동전의 종류 입력
		for(int m=1; m<=n; m++)
			scanf("%d", &money[m]);

		//만들어야 할 금액
		scanf("%d", &m);
		solve(n, m);
	}

	return 0;
}
void solve(int n, int m)
{
	s[0] = 1;

	for(int i=1; i<=n; i++){
		for(int j=money[i]; j<=m; j++){
			s[j] += s[j-money[i]];
		}
	}

	printf("%d\n", s[m]);
}