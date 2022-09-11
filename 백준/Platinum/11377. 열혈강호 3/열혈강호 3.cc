#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define N 1000

using namespace std;

vector<int> g[N + 1];
int visit[N + 1], match[N + 1];


bool DFS(int x)
{
	for (int i = 0; i < g[x].size(); i++) {

		int tmp = g[x][i];

		if (visit[tmp]) continue;
		visit[tmp] = 1;

		if (match[tmp] == 0 || DFS(match[tmp])) {
			match[tmp] = x;
			return true;
		}
	}
	return false;
}


int main(void)
{
	int n, m, k, a, b;
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);

		for (int j = 0; j < a; j++) {
			scanf("%d", &b);

			g[i].push_back(b);
		}
	}

	int sol = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (DFS(i)) sol++;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (DFS(i)) {
			sol++;
			cnt++;
		}
		if (cnt == k) break;
	}
	
	printf("%d\n", sol);
	return 0;
}
