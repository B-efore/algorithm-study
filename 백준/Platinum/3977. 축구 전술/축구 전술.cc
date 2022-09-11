#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#define N 100000
using namespace std;

int n, m;
int cnt, scc_cnt;
int visit[N + 1], mark[N + 1], scc_number[N + 1], indegree[N + 1];
vector<int> g[N + 1];
vector<vector<int>> scc;
stack<int> s;

int DFS(int cur)
{
	s.push(cur);
	visit[cur] = ++cnt;
	int parent = visit[cur];

	for (int next : g[cur]) {
		if (!visit[next]) parent = min(parent, DFS(next));
		else if (!mark[next]) parent = min(parent, visit[next]);
	}

	if (parent == visit[cur])
	{
		vector<int> v;
		scc_cnt++;

		while (true) {

			int tmp = s.top(); s.pop();
			v.push_back(tmp);
			scc_number[tmp] = scc_cnt;
			mark[tmp] = 1;
			
			if (tmp == cur) break;
		}

		scc.push_back(v);
	}

	return parent;
}

void Init()
{
    cnt = 0; scc_cnt = 0;
	memset(visit, 0, sizeof(visit));
	memset(mark, 0, sizeof(mark));
	memset(scc_number, 0, sizeof(scc_number));
	memset(indegree, 0, sizeof(indegree));

	scc.clear();

	for (int i = 0; i < N; i++)
		g[i].clear();
}

int main(void)
{
	int t;
	scanf("%d", &t);

	while (t--) {

		Init();

		scanf("%d %d", &n, &m);

		int a, b;

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
		}

		for (int i = 0; i < n; i++)
			if (!visit[i]) DFS(i);

		for (int i = 0; i < n; i++) {
			for (int j : g[i]) {
				if (scc_number[i] != scc_number[j]) {
					indegree[scc_number[j]]++;
				}
			}
		}

		int idx = 0;
		int check = 0;
		
		for (int i = 1; i <= scc.size(); i++) {
			if (indegree[i] == 0) {
				idx = i - 1;
				check++;
			}
		}
		
		if (check == 1) {

			sort(scc[idx].begin(), scc[idx].end());

			for (int j = 0; j < scc[idx].size(); j++)
				printf("%d\n", scc[idx][j]);
		}
		else
			printf("Confused\n");
        printf("\n");
	}
}