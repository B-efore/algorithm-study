#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100000
#define DIV 1000000000

using namespace std;

int n, m;

struct edge {
	int x;
	int y;
	int w;
};

vector<edge> e;
int parent[N + 1];
int num[N + 1];

int find(int x)
{
	while (x != parent[x])
		x = parent[x];
	return x;
}

void set_union(int v1, int v2)
{
	int a = find(v1);
	int b = find(v2);

	if (num[a] > num[b]) {
		parent[b] = a;
		num[a] += num[b];
		num[b] = 1;
	}
	else {
		parent[a] = b;
		num[b] += num[a];
		num[a] = 1;
	}
}

bool comp(edge a, edge b)
{
	if (a.w < b.w)
		return false;
	return true;
}
int main(void)
{
	long long sum = 0;
	int i, x, y, w;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		e.push_back({ x, y, w });
		
		sum += w;
	}

	sort(e.begin(), e.end(), comp);

	for (i = 1; i <= n; i++){
		parent[i] = i;
		num[i] = 1;
	}

	long long solve = 0;

	for (i = 0; i <e.size(); i++) {

		int v1 = find(e[i].x);
		int v2 = find(e[i].y);
		int cost = e[i].w;


		if (v1 != v2) {
			solve += sum * num[v1] * num[v2];
			set_union(v1, v2);
		}
		sum -= cost;
	}

	printf("%lld\n", solve % DIV);
}