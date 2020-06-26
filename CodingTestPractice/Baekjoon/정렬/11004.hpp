#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	cout << v[k - 1];

	return 0;
}