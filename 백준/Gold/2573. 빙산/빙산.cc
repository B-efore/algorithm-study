#include <cstdio>
#include <cstring>
#define N 300

int n, m;
int map[N + 1][N + 1];
int melt[N + 1][N + 1];
bool visit[N + 1][N + 1];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void DFS(int y, int x);
int main(void)
{
	int number, year = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	while (1){

		number = 0;
		memset(visit, 0, sizeof(visit));
		memset(melt, 0, sizeof(melt));
		
		// 빙산 찾기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visit[i][j]) {
					DFS(i, j);
					number++;
				}
			}
		}

		if (number >= 2) break;
		if (number == 0) {
			year = 0;
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] - melt[i][j] >= 0)
					map[i][j] -= melt[i][j];
				else
					map[i][j] = 0;
			}
		}

		year++;
	}

	printf("%d\n", year);
	return 0;
}

void DFS(int y, int x)
{
	visit[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

		if (map[ny][nx] && !visit[ny][nx])
			DFS(ny, nx);
		else if(!map[ny][nx])
			melt[y][x]++;
	}
}