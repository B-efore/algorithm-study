#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct point {
	long long x;
	long long y;
};

vector<point> p;

long long ccw(point a, point b, point c) {
	return (a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y);
}

bool comp1(point a, point b)
{
	if (a.y > b.y) return false;
	if (a.y == b.y && a.x > b.x) return false;
	return true;
}

bool comp2(point a, point b) {
	long long val = ccw(p[0], a, b);

	if (val) return val > 0;
	else if (a.y != b.y) return a.y < b.y;
	else return a.x < b.x;
}

int main(void)
{
	int i, n;

	scanf("%d", &n);

	p.resize(n);

	for (i =0; i < n; i++) {
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}

	sort(p.begin(), p.end(), comp1);
	sort(p.begin() + 1, p.end(), comp2);

	point tmp1, tmp2;
	stack<point> s;
	s.push(p[0]); s.push(p[1]);

	for (i = 2; i < n; i++) {
		while (s.size() >= 2) {
			tmp2 = s.top(); s.pop();
			tmp1 = s.top();

			if (ccw(tmp1, tmp2, p[i]) > 0) {
				s.push(tmp2);
				break;
			}
		}

		s.push(p[i]);
	}

	printf("%d\n", s.size());
}