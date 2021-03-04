#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int>> v;
int N;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N; cin.ignore();
	v.resize(N);
	for (auto& obj : v) {
		getline(cin, obj.first);
		int len = obj.first.size();
		for (int i = 0; i < len; ++i)
			if (isdigit(obj.first[i]))obj.second += obj.first[i] - '0';
	}

	sort(v.begin(), v.end(), [](pair<string, int>& obj1, pair<string, int>& obj2)->bool {
		if (obj1.first.size() != obj2.first.size()) return obj1.first.size()<obj2.first.size();
		else {
			if (obj1.second != obj2.second) return obj1.second<obj2.second;
			else return obj1.first < obj2.first;
		}
	});

	for (auto& obj : v)
		cout << obj.first << '\n';

	return 0;
}