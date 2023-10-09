#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map <string, int> um;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, ans = 0;
	string str;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		um.insert(make_pair(str, 0));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;
		if (um.find(str) != um.end())
			um[str]++;
	}

	for (auto iter = um.begin(); iter != um.end(); iter++)
		ans += iter->second;

	cout << ans << '\n';
	return 0;
}