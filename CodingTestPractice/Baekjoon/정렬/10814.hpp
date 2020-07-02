#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	vector<pair<int, string> > v;
	int cnt;
	cin >> cnt; cin.ignore();
	while (cnt--)
	{
		getline(cin, input);
		auto idx = input.find_first_of(' ');
		int age = atoi(input.substr(0, idx).c_str());
		string name(input.begin() + idx+1, input.end());
		v.push_back({ age,name });
	}
	stable_sort(v.begin(), v.end(), [&](pair<int, string>obj1, pair<int, string>obj2)->bool {
		if (obj1.first < obj2.first)return true;
		else return false;
	});
	for (auto& [age, name] : v)
		cout << age << " " << name << '\n';
	return 0;
}