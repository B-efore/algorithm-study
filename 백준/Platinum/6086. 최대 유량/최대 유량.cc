#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 52

using namespace std;

int n;
int parent[MAX + 1];
int pipe[MAX + 1][MAX + 1];
int flow[MAX + 1][MAX + 1];

char cToI(char num)
{
    if (num >= 'A' && num <= 'Z')
        return (num - 'A');
    else
        return (num - 'a' + 26);
}

int solve()
{
    int i, s, e, cur, max = 0;
    s = cToI('A');
    e = cToI('Z');

    while (1)
    {
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            cur = q.front(); q.pop();
            for (i = 0; i < MAX; i++) {
                if (flow[cur][i] < pipe[cur][i] && parent[i] == -1) {
                    parent[i] = cur;
                    q.push(i);
                    if (i == e) break;
                }
            }
        }

        if (parent[e] == -1) break;

        int f = 1e9;

        for (i = e; i != s; i = parent[i])
            f = min(f, pipe[parent[i]][i] - flow[parent[i]][i]);

        for (i = e; i != s; i = parent[i]) {
            flow[parent[i]][i] += f;
            flow[i][parent[i]] -= f;
        }
        max += f;
    }

    return max;
}

int main()
{
    char u, v;
    int a, b, w;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c %d", &u, &v, &w);
        a = cToI(u); b = cToI(v);
        pipe[a][b] += w;
        pipe[b][a] += w;
    }

    printf("%d\n", solve());
}