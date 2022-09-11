#include <cstdio>
#define R 10000
#define C 500
char map[R + 1][C + 1];
int visit[R + 1][C + 1];
// 오른쪽 위, 옆, 아래
int dy[3] = {-1, 0, 1 };
int dx[3] = { 1, 1, 1 };
int r, c;
int solve(int y, int x);
int main(void)
{
	int ans = 0;
	scanf("%d %d", &r, &c);
	getchar();

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			scanf("%c", &map[i][j]);
		getchar();
	}

	for (int i = 0; i < r; i++) {
		solve(i, 0);
	}

	for (int i = 0; i < r; i++) {
		ans += visit[i][c - 1];
	}

	printf("%d\n", ans);
	return 0;
}

int solve(int y, int x)
{
	visit[y][x] = 1;

	if (x == c - 1) return 1;

	for (int i = 0; i < 3; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= r || nx < 0 || nx >= c || visit[ny][nx]) continue;
		if (map[ny][nx] == 'x') continue;

		if(solve(ny, nx)) return 1;
	}

	return 0;
}