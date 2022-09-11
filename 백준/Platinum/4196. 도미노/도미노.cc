#include <cstdio>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#define N 100000
using namespace std;

int n, m;
int cnt, scc_cnt;
int visit[N + 1], mark[N + 1], scc_number[N + 1], indegree[N + 1];
vector<vector<int>> scc;
vector<vector<int>> g;
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

    if (parent == visit[cur]) {

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

void SCC()
{
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) DFS(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {
            if (scc_number[i] != scc_number[j]) {
                //scc_adj[scc_number[i]].insert(scc_number[j]);
                indegree[scc_number[j]]++;
            }
        }
    }

}

void Init()
{
    cnt = 0; scc_cnt = 0;

    memset(visit, 0, sizeof(visit));
    memset(mark, 0, sizeof(mark));
    memset(indegree, 0, sizeof(indegree));
    memset(scc_number, 0, sizeof(scc_number));

    while (!s.empty()) s.pop();

    g.clear();
    g.resize(N + 1);
    scc.clear();
}

int main(void)
{
    int t, x, y;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {

        Init();

        scanf("%d %d", &n, &m);

        for (int j = 0; j < m; j++) {
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }

        SCC();

        int solve = 0;
        for (int i = 1; i <= scc.size(); i++) {
            if (indegree[i] == 0) solve++;
        }

        printf("%d\n", solve);
    }

    return 0;
}