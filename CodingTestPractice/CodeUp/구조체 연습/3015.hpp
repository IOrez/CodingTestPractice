#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int,string> > v(n);
	for (auto& p : v)
		cin >> p.second >> p.first;
	stable_sort(v.begin(), v.end(), [&](pair<int, string> obj1, pair<int, string> obj2){
		if (obj1.first > obj2.first)return true;
		return false;
	});

	for (int i = 0; i < m; ++i)
		cout << v[i].second << endl;


	return 0;
}