#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int T, n;
string inputfunc, inputarr;
deque<int> v;

bool flag = false;

int ToInt(string& inputarr, int& idx,int& cnt) {
	int value = 0, i = idx;
	bool check = false;
	for (i = idx; inputarr[i] != ']' && inputarr[i] != ','; ++i) {
		value *= 10;
		value += (inputarr[i] - '0');
		check = true;
	}
	idx = i+1;
	if(check)
		cnt++;
	return value;
}

bool Solution(string& inputfunc) {
	
	for (int i = 0; i < inputfunc.size(); ++i) {
		if (inputfunc[i] == 'R') flag = !flag;
		else if (inputfunc[i] == 'D') {
			if (v.empty()) {
				cout << "error" << '\n';
				return false;
			}
			else {
				if (!flag)v.pop_front();
				else v.pop_back();
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T; cin.ignore();
	while (T--) {
		flag = false;
		v.clear();
		getline(cin, inputfunc);
		cin >> n; cin.ignore();
		getline(cin, inputarr);
		int idx = 1, cnt = 0;
		while (cnt != n)
			v.push_back(ToInt(inputarr, idx, cnt));

		bool result = Solution(inputfunc);
		int value = 0;
		if (result) {
			cout << "[";
			if (!v.empty()) {
				while (v.size() != 1) {
					if (!flag) {
						value = v.front();
						v.pop_front();
					}
					else {
						value = v.back();
						v.pop_back();
					}
					cout << value << ",";
				}
				cout << v.front();
				v.pop_front();
			}
			cout<<"]"<<'\n';
		}
	}
	return 0;
}