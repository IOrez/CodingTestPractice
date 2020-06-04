#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, bool> m;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string input;
	cin >> n;
	vector<pair<int, string> > v;
	for(int i =0;i<n;++i)
	{
		cin >> input;
		if (m.find(input) == m.end())
		{
			m.insert(make_pair(input,true));
			v.push_back({ input.size(),input });
		}
	}
	sort(v.begin(), v.end(), [&](pair<int, string> obj1, pair<int, string>obj2)->bool{
		if (obj1.first < obj2.first)return true;
		else if (obj1.first == obj2.first && obj1.second < obj2.second)return true;
		return false;
	});
	cout << v[0].second<<'\n';
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].second == v[i - 1].second)continue;
		cout << v[i].second << '\n';
	}


	return 0;
}