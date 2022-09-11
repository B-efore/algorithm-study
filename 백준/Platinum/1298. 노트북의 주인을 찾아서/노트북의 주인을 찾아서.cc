#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#define N 100
using namespace std;

int n, m;
int visit[N + 1], match[N + 1];
vector<int> g[N + 1];
vector<vector<int>> scc;

bool DFS(int x)
{
	for (int i = 0; i < g[x].size(); i++) {
		int num = g[x][i];

		if (visit[num]) continue;
		visit[num] = 1;

		// num번째 노트북을 선택한 사람이 없거나, num을 선택한 사람이 다른 선택이 가능하다면
		// 매칭이 이루어진 경우
		if (match[num] == 0 || DFS(match[num])) {
			match[num] = x;
			return true;
		}
	}

	// 매칭이 이루어지지 않음
	return false;
}

int main(void)
{
	scanf("%d %d", &n, &m);
	
	int a, b, cnt=0;

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if(DFS(i)) cnt++;
	}

	printf("%d\n", cnt);
}