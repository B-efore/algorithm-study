#include <cstdio>
#include <cstring>
#include <queue>
#define INF 987654321
#define N 400
using namespace std;

int sol;
int visit[N + 1];
int flow[N + 1][N + 1];
int pipe[N + 1][N + 1];

int solve()
{
	int s = 1;
	int e = 2;

	while (true) {

		memset(visit, -1, sizeof(visit));
		queue<int> q;
		q.push(s);

		while (!q.empty()) {

			int tmp = q.front(); q.pop();

			for (int i = 1; i <= N; i++) {
				if (flow[tmp][i] < pipe[tmp][i] && visit[i] == -1) {
					q.push(i);
					visit[i] = tmp;
					if (i == e) break;
				}
			}
		}



		if (visit[e] == -1) break;

		int f = INF;

		for (int i = e; i != s; i = visit[i])
			f = min(f, pipe[visit[i]][i] - flow[visit[i]][i]);

		for (int i = e; i != s; i = visit[i]) {
			flow[visit[i]][i] += f;
			flow[i][visit[i]] -= f;
		}

		sol += f;
	}

	return sol;
}

int main(void)
{
	int n, p, a, b;
	scanf("%d %d", &n, &p);

	for (int i = 0; i < p; i++) {
		scanf("%d %d", &a, &b);
		pipe[a][b] = 1;
	}

	printf("%d\n", solve());
	return 0;
}