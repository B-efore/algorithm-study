#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> v;
int n;
void solve(int cnt);
bool check(int cnt);
void answer();
int main(void)
{
	scanf("%d", &n);
	solve(0);
	return 0;
}

void solve(int cnt)
{
	if (!check(cnt)) return;
	if (cnt == n) {
		answer();
		exit(0);
	}

	for (int i = 1; i <= 3; i++)
	{
		v.push_back(i);
		solve(cnt + 1);
		v.pop_back();
	}
}

bool check(int cnt)
{
	for (int size = 1; size <= cnt / 2; size++){

		int tmp = 0;

		for (int i = 0; i < size; i++) {
			if (v[cnt - 1 - i] == v[cnt - 1 - i - size]) tmp++;
		}

		if (tmp == size) return false;
	}

	return true;
}

void answer()
{
	for (int i = 0; i < v.size(); i++) {
		printf("%d", v[i]);
	}
	printf("\n");
}