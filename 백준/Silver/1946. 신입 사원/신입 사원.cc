#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int a, b, t, n, ans, check;
	scanf("%d", &t);

	while (t--) {
		
		vector<pair<int, int>> v;
		ans = 0;

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		sort(v.begin(), v.end());
		check = v[0].second;

		for (int i = 0; i < n; i++) {

			if (v[i].second <= check) {
				ans++;
				check = v[i].second;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}