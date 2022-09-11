#include <stdio.h>
#define N 1000000
int num[N + 1];
//길이가 i일 때 마지막 원소
int L[N + 1];
int BSearch(int start, int end, int number);
int main(void)
{
	int i, j, n, idx;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	L[1] = num[1];

	for (i = 1; i <= n; i++) {
		idx = BSearch(1, n, num[i]);
		L[idx] = num[i];
	}

	for (i = n; i >=1; i--) {
		if (L[i] != 0) {
			printf("%d ", i);
			break;
		}
	}

	return 0;
}
int BSearch(int start, int end, int number)
{
	int mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (L[mid] == 0) {
			end = mid - 1;
		}
		else if (L[mid] >= number) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return start;
}