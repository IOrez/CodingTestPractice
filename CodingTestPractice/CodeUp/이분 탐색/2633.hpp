#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (auto& i : v)cin >> i;
	auto iter = lower_bound(v.begin(), v.end(), K);
	cout << iter - v.begin() + 1;

	return 0;
}