#include <iostream>
#include <algorithm>
#define N 20000
using namespace std;
string arr[N + 1];

int compare(string a, string b);
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i - 1]) continue;
		cout << arr[i] << "\n";
	}

	return 0;

}

int compare(string a, string b)
{
	if (a.length() == b.length()) return a < b;
	else return (a.length() < b.length());
}