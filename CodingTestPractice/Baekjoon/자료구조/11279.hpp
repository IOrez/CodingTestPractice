#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int N;
int num;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num;
		if (num == 0) {
			if (v.empty())cout << 0 << '\n';
			else {
				cout << v[0] << '\n';
				pop_heap(v.begin(), v.end());
				v.pop_back();
			}
			continue;
		}
		v.push_back(num);
		push_heap(v.begin(), v.end());
	}
	return 0;
}