#include <stdio.h>
#include <math.h>

int n, r, c;
int solve(int y, int x, int n);

int main(void)
{
	scanf("%d %d %d", &n, &r, &c);
	int s = solve(0, 0, pow(2, n));
	printf("%d\n", s);
	return 0;
}

int solve(int y, int x, int n)
{
	if(n==1) return 0;

	if(r<y+n/2 && c<x+n/2){
		return solve(y, x, n/2);
	}
	else if(r<y+n/2 && c>=x+n/2){
		return solve(y, x+n/2, n/2) + n/2 * n/2;
	}
	else if(r>=y+n/2 && c<x+n/2){
		return solve(y+n/2, x, n/2) + n/2 * n/2 * 2;
	}
	else{
		return solve(y+n/2, x+n/2, n/2) + n/2 * n/2 * 3;
	}
}