#include <cstdio>
#include <cstring>
#include <vector>
#define N 200
using namespace std;

int check[N + 1], match[N + 1];
vector<int> g[N + 1];

bool DFS(int x)
{
	for (int i = 0; i < g[x].size(); i++) {
		int tmp = g[x][i];

		if (check[tmp]) continue;
		check[tmp] = true;

		if (match[tmp] == 0 || DFS(match[tmp])) {
			match[tmp] = x;
			return true;
		}
	}

	return false;
}

int main(void)
{
	int n, m, w, x, cnt = 0;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &w);

		for (int j = 0; j < w; j++) {
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (DFS(i)) cnt++;
	}
	
	printf("%d\n", cnt);
}