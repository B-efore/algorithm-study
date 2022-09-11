#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> F;

int main(void)
{
	int i, j, n, S, E, max, ans = 0;
	scanf("%d", &n);


	for (i = 0; i < n; i++) {
		int sm, sd, em, ed;
		scanf("%d %d %d %d", &sm, &sd, &em, &ed);
		S = sm * 100 + sd;
		E = em * 100 + ed;
		F.push_back({ S, E });
	}

	sort(F.begin(), F.end());

	S = 301, E = 301; j = 0;

	while (E <= 1130 && j < n) {

		max = 0;

		while (j < n && F[j].first <= E) {
			if (F[j].second > max) {
				max = F[j].second;
			}
			j++;
		}

		// 탐색 끝
		if (max == 0) {
			break;
		}

		E = max;
		ans++;
	}

	if (E > 1130)
		printf("%d\n", ans);
	else
		printf("0\n");

	return 0;
}