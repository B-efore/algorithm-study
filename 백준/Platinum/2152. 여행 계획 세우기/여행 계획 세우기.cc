#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#define N 10000
using namespace std;

int n, m, s, t, cnt, scc_cnt;
int visit[N + 1], mark[N + 1], scc_number[N + 1], solve[N + 1];
vector<vector<int>> scc;
vector<int> g[N + 1];
set<int> scc_adj[N + 1];
stack<int> _stack;

int DFS(int cur)
{
    _stack.push(cur);
    visit[cur] = ++cnt;

    int parent = visit[cur];
    for (int next : g[cur]) {
        //아직 방문하지 않음
        if (!visit[next])
            parent = min(parent, DFS(next));
        //방문했으나 아직 SCC로 성립하지 않음
        else if (!mark[next])
            parent = min(parent, visit[next]);
    }

    //SCC 추출
    if (parent == visit[cur]) {

        vector<int> v;
        scc_cnt++;

        while (true) {
            int tmp = _stack.top();
            _stack.pop();

            v.push_back(tmp);
            scc_number[tmp] = scc_cnt;
            mark[tmp] = 1;

            if (tmp == cur) break;
        }
        scc.push_back(v);
    }

    return parent;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int i, a, b;

    cin >> n >> m >> s >> t;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (i = 1; i <= N; i++)
        if (!visit[i])
            DFS(i);

    for (i = 1; i <= N; i++) {
        for (int j : g[i]) {
            if (scc_number[i] != scc_number[j])
                scc_adj[scc_number[i]].insert(scc_number[j]);
        }
    }

    int start = scc_number[s];
    int end = scc_number[t];
    solve[start] = (int)scc[start - 1].size();
    // printf("start: %d, end: %d, solve[%d] = %d\n", start, end, start, solve[start]);

    for (i = start; i >= end; i--) {
        if (solve[i] == 0) continue;
        for (int j : scc_adj[i]) {
          // printf("slove[%d] = %d\n", j, solve[j]);
          // printf("solve[%d] = %d\n", i, solve[i]);
          // printf("scc[%d].size() = %d\n", tmp, (int)scc[tmp].size());
          
            solve[j] = max(solve[j], solve[i] + (int)scc[j-1].size());
        }
    }

    cout << solve[end] << "\n";
    return 0;
}