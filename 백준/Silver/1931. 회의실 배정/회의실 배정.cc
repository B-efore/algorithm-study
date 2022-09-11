#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int>> T;
bool compare(pair<int, int> a, pair<int, int> b);
int main(void)
{
	int s, e, n;
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &e);
		T.push_back({ e,s });
	}

	sort(T.begin(), T.end());

	int check = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (T[i].second >= check) {
			check = T[i].first;
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}