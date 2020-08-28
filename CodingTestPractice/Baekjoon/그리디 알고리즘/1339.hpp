#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int N;
int table[26];
string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int s = 1;
		cin >> input;
		for (auto iter = input.rbegin(); iter != input.rend(); ++iter) {
			table[*iter - 'A'] += s;
			s *= 10;
		}
	}
	sort(table, table + 26,greater<int>());
	int s = 0;
	for (auto i = 9, idx = 0; i >= 0; --i, idx++)
		s += i * table[idx];
	cout << s;
	return 0;
}