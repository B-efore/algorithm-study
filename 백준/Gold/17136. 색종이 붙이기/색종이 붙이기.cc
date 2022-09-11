#include <cstdio>
#include <algorithm>
#define N 10
#define INF 987654321
using namespace std;

int ans = INF;
int paper[N+1][N+1];
int paperCnt[5];

bool canAttach(int y, int x, int num)
{
	for (int i = y; i < y + num; i++) {
		for (int j = x; j < x + num; j++) {
			if (paper[i][j] == 0)
				return false;
		}
	}

	return true;
}

void attachPaper(int y, int x, int n, int num)
{
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			paper[i][j] = num;
		}
	}
}

void DFS(int y, int x, int attached)
{
	while (paper[y][x] == 0) {
		if (++x >= N) {
			if (++y >= N) {
				ans = min(ans, attached);
				return;
			}
			x = 0;
		}
	}

	if (ans <= attached) return;
	for (int i = 5; i > 0; i--) {
		if (x + i > N || y + i > N || paperCnt[i] >= 5) continue;
		if (canAttach(y, x, i)) {
			attachPaper(y, x, i, 0);
			paperCnt[i]++;

			DFS(y, x, attached + 1);
			
			attachPaper(y, x, i, 1);
			paperCnt[i]--;

		}
	}
}

int main(void)
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &paper[i][j]);

	DFS(0, 0, 0);
	
	if (ans == INF) ans = -1;

	printf("%d\n", ans);
}