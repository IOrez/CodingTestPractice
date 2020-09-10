#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<int> v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	for (auto& i : v)
		cout << i << '\n';
	return 0;
}