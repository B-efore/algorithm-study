#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 8

int dy[N + 1] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dx[N + 1] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
char map[N + 1][N + 1];
bool visit[N + 1][N + 1];

void reset_map();

int main(void)
{
	int s;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%c", &map[i][j]);
		getchar();
	}

	queue<pair<int, int>> q;
	q.push({ 7, 0 });

	while (!q.empty())
	{
		s = q.size();
		memset(visit, 0, sizeof(visit));

		while (s--) {

			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (map[y][x] == '#') continue;

			for (int i = 0; i < N+1; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N || visit[ny][nx]) continue;
				if (map[ny][nx] == '#') continue;

				// 도착
				if (ny == 0 && nx == 7) {
					printf("1\n");
					exit(0);
				}

				visit[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
		reset_map();
	}

	printf("0\n");
	return 0;
}

void reset_map()
{
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < N; j++)
			map[i + 1][j] = map[i][j];

	for (int i = 0; i < N; i++)
		map[0][i] = '.';
}