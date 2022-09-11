#include <cstdio>
#include <algorithm>
using namespace std;
int D, P, maxNumber = -1;
void solve(int number, int multiple, int setNumber);
bool check(int number);
int main(void)
{
	scanf("%d %d", &D, &P);
	solve(1, 0, 2);
	printf("%d\n", maxNumber);
}

void solve(int number, int multiple, int setNumber)
{
	if (multiple == P) {
		maxNumber = max(maxNumber, number);
		return;
	}

	for (int i = setNumber; i <= 9; i++) {
		int checkNumber = number * i;
		if (check(checkNumber)) {
			solve(checkNumber, multiple + 1, i);
		}
	}
}

bool check(int number)
{
	int cnt = 0;

	while (number > 0) {
		number /= 10;
		cnt++;
	}

	return cnt <= D;
}