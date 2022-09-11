#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, string>> arr;

int compare(pair<int, string> a, pair<int, string> b);
int main(void)
{
	int n;
	int a;
	string b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back({ a,b });
	}

	stable_sort(arr.begin(), arr.end(), compare);

	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";
}

int compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}