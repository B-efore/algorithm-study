#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, l;
vector<int> v;

int main(void)
{
	int c;

	scanf("%d %d %d", &n, &m, &l);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		v.push_back(c);
	}
	
	v.push_back(0);
	v.push_back(l);

	sort(v.begin(), v.end());

	int start = 1, end = l-1, mid;

	while (start <= end) {

		int cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < v.size() - 1; i++) {
			
			int d = v[i + 1] - v[i];
			cnt += (d / mid);
			if (d % mid == 0) cnt--; //겹치는 경우
		}

		// 간격을 줄여야 함
		if (cnt <= m) {
			end = mid - 1;
		}
		// 간격을 늘려야 함
		else {
			start = mid + 1;
		}
	}

	printf("%d\n", start);
	return 0;
}