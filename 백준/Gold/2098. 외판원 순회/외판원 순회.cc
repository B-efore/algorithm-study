#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 16
#define INF 987654321
using namespace std;

int w[N + 1][N + 1];
int p[N + 1][1 << 16];
int n, answer;

int TSP(int cur, int visit)
{
	if (visit == (1<<n)-1) {
		if (w[cur][0] == 0) return INF;
		else return w[cur][0];
	}

	if (p[cur][visit] != -1) return p[cur][visit];

	p[cur][visit] = INF;

	for (int i = 0; i < n; i++) {

		if ((visit & (1 << i)) || w[cur][i]==0) continue;

		p[cur][visit] = min(p[cur][visit], w[cur][i] + TSP(i, visit | (1 << i)));
	}

	return p[cur][visit];
}

int main(void)
{
	int i, j;
	scanf("%d", &n);
	answer = (1 << n) - 1;

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			scanf("%d", &w[i][j]);

	memset(p, -1, sizeof(p));
	printf("%d\n", TSP(0, 1));
}