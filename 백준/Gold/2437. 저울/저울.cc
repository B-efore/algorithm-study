#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(void)
{
	int n;
	scanf("%d", &n);

	arr.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	int check = 1;

	for (int i = 0; i < n; i++) {
		if (check < arr[i])
			break;

		check += arr[i];
	}

	printf("%d\n", check);
	return 0;
}