#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000
using namespace std;

int visit[N + 1], match[N + 1];
vector<int> g[N + 1];

bool DFS(int x)
{
	for (int i = 0; i < g[x].size(); i++) {
		int tmp = g[x][i];

		if (visit[tmp]) continue;
		visit[tmp] = true;

		if (match[tmp] == 0 || DFS(match[tmp])) {
			match[tmp] = x;
			return true;
		}
	}
	return false;
}

void Init()
{
	memset(visit, 0, sizeof(visit));
	memset(match, 0, sizeof(match));

	for (int i = 0; i < N; i++)
		g[i].clear();
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--) {

		Init();

		int n, m, a, b;
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= m; i++) {
			scanf("%d %d", &a, &b);

			for (int j = a; j <= b; j++)
				g[i].push_back(j);
		}

		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			memset(visit, 0, sizeof(visit));
			if (DFS(i)) cnt++;
		}

		printf("%d\n", cnt);
	}
}