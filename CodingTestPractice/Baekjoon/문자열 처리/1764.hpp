#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string>& v,string str,int left,int right) {
	if (left > right)return -1;
	int mid = (left + right) / 2;
	if (v[mid] == str)return mid;
	int ret = -1;
	if (v[mid] > str)ret = solution(v, str, left, mid - 1);
	else ret = solution(v, str, mid + 1, right);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M;
	string input;
	vector<string> v;
	vector<string> ov;
	cin >> N >> M;
	cin.ignore();
	while (N--) {
		getline(cin, input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	while (M--) {
		getline(cin, input);
		if (solution(v, input, 0, v.size() - 1) != -1)
			ov.push_back(input);
	}
	sort(ov.begin(), ov.end());
	cout << ov.size() << '\n';
	for (auto& str : ov)
		cout << str << '\n';
	return 0;
}