#include <cstdio>
#include <cmath>
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

long long Dist(point a, point b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void)
{
	int i, n;
	scanf("%d", &n);

	p.resize(n);

	for (i = 0; i < n; i++)
		scanf("%lld %lld", &p[i].x, &p[i].y);

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

	vector<point> v;
	long long tmp;
	int LPoint = 0, RPoint = 0;
	int size = s.size();

	v.resize(size);

	for (i = size-1; i >= 0; i--) {
		v[i] = s.top();
		s.pop();
	}

	for (i = 0; i < size; i++) {
		if (v[i].x < v[LPoint].x) LPoint = i;
		if (v[i].x > v[RPoint].x) RPoint = i;
	}

	tmp = Dist(v[LPoint], v[RPoint]);
	point origin; origin.x = 0; origin.y = 0;

	for (i = 0; i < size; i++) {

		tmp1.x = v[(LPoint + 1) % size].x - v[LPoint].x;
		tmp1.y = v[(LPoint + 1) % size].y - v[LPoint].y;

		tmp2.x = v[RPoint].x - v[(RPoint + 1) % size].x;
		tmp2.y = v[RPoint].y - v[(RPoint + 1) % size].y;

		if (ccw(origin, tmp1, tmp2) > 0)
			LPoint = (LPoint + 1) % size;
		else
			RPoint = (RPoint + 1) % size;

		if (Dist(v[LPoint], v[RPoint]) > tmp)
			tmp = Dist(v[LPoint], v[RPoint]);
	}

	printf("%.7lf\n", sqrt(tmp));

}