#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}