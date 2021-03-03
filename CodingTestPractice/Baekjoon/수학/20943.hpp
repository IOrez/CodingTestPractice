#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<double, int> m;
vector<int> temp;
vector<int> v;
int N,a,b,c;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b >> c;

		double grad = -(double)a / b;

		auto iter = m.find(grad);
		if (iter != m.end())iter->second++;
		else m.insert({ grad ,1 });
	}

	int ans = 0;
	for (auto iter = m.begin(); iter != m.end(); ++iter) {
		v.push_back(iter->second);
		temp.push_back(0);
	}

	if (v.size() == 1)
		cout << 0;
	else {
		temp[0] = temp[1] = 1;
		do {
			ans += v[temp[]]

		} while (next_permutation(temp.begin(), temp.end());

	}

}