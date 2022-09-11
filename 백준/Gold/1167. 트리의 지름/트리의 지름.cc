#include <cstdio>
#include <cstring>
#include <vector>
#define N 100000
using namespace std;
int maxIdx, maxDist;
bool visit[N+1];
vector<pair<int, int>> tree[N+1];
void DFS(int idx, int distance);
int main(void)
{
	int v, s, e, w;
	scanf("%d", &v);

	// Input
	for(int i=0; i<v; i++)
	{
		scanf("%d", &s);
		while(true)
		{
			scanf("%d", &e);
			if(e==-1) break;
			scanf("%d", &w);

			tree[s].push_back({e, w});
			tree[e].push_back({s, w});
		}
	}

	// Solve
	DFS(s, 0);
	memset(visit, 0, sizeof(visit));
	DFS(maxIdx, 0);

	printf("%d\n", maxDist);
	return 0;
}

void DFS(int idx, int distance)
{
	visit[idx] = true;

	if(maxDist<distance)
	{
		maxIdx = idx;
		maxDist = distance;
	}

	for(int i=0; i<tree[idx].size(); i++)
	{
		int next = tree[idx][i].first;
		int nextD = tree[idx][i].second;

		if(visit[next]) continue;

		DFS(next, distance + nextD);
	}
}