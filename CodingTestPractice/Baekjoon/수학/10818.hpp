#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)
		cin >> i;
	cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end());
	return 0;
}