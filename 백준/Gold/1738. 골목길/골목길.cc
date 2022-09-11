#include <cstdio>
#include <vector>
#include <queue>
#define N 100
#define INF 987654321
using namespace std;

int n, m;
int dist[N + 1];
int pre[N + 1];
bool visit[N + 1];
vector<pair<int, pair<int, int>>> edge;
vector<int> e[N + 1];
queue<int> q;

void solve(int n);

int main(void)
{
	int i, j, k, u, v, w;

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		edge.push_back({ w, {u, v} });
		e[v].push_back(u);
	}

	for (i = 1; i <= n; i++) {
		dist[i] = INF;
		visit[i] = false;
	}

	dist[1] = 0;
	pre[1] = 1;

	q.push(n);
	visit[n] = true;

	while (!q.empty()) {
		int tmp = q.front(); q.pop();

		for (i = 0; i < e[tmp].size(); i++) {
			int next = e[tmp][i];

			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}

	int cycle=0;

	for (i = 1; i <= n; i++) {
		for (j = 0; j < edge.size(); j++) {
			u = edge[j].second.first;
			v = edge[j].second.second;
			w = -edge[j].first;

			if (dist[u] == INF) continue;
			if (dist[u] + w < dist[v]) {

				if (i == n && visit[u]) {
					cycle = true;
				}


				dist[v] = dist[u] + w;
				pre[v] = u;
			}
		}
	}


	if (cycle!=0)
		printf("%d\n", -1);
	else
		solve(n);

}

void solve(int cur) {
	if (cur == 1) {
		printf("%d ", cur);
		return;
	}
	solve(pre[cur]);
	printf("%d ", cur);
}