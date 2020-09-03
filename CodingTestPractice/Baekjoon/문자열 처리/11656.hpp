#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string input;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> input;
	size_t i = 0;
	while (i < input.size())
		v.push_back(input.substr(i++));
	
	sort(v.begin(), v.end());
	for (auto& str : v)
		cout << str << '\n';
	return 0;
}