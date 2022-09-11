#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e15
#define N 10000
#define K 20
using namespace std;

void solve();

vector<pair<int, int>> edge[N + 1];
// n번 도시까지 k개의 포장 도로수를 거쳐 오는 비용의 최솟값
long long cost[N + 1][K + 1];
int n, m, k;

int main()
{
	int i, s, e, w;

	scanf("%d %d %d", &n, &m, &k);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &s, &e, &w);
		edge[s].push_back({ e, w });
		edge[e].push_back({ s, w });
	}

	solve();

	long long sol = INF;
	for (i = 0; i <= k; i++) sol = min(sol, cost[n][i]);
	printf("%lld\n", sol);
}

void solve()
{
	priority_queue <pair<long long, pair<int, int>>> queue;
	int i, j, cur, cnt, tmp;
	long long w, tmp_w;

	for (i = 1; i <= n; i++)
		for (j = 0; j <= k; j++) {
			cost[i][j] = INF;
		}

	cost[1][0] = 0;
	queue.push({ 0, {1, 0} });

	while (!queue.empty())
	{
		cur = queue.top().second.first;
		cnt = queue.top().second.second;
		w = -queue.top().first;
		queue.pop();

		if (w > cost[cur][cnt]) continue;

		for (int i = 0; i < edge[cur].size(); i++) {
			tmp = edge[cur][i].first;
			tmp_w = edge[cur][i].second + w;

			if (cost[tmp][cnt] > tmp_w) {
				cost[tmp][cnt] = tmp_w;
				queue.push({ -tmp_w, {tmp, cnt} });
			}

			if ((cost[tmp][cnt + 1] > w) && (k >= cnt + 1)) {
				cost[tmp][cnt + 1] = w;
				queue.push({ -w, {tmp, cnt + 1} });
			}
		}
	}
}