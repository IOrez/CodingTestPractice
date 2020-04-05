#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	vector<int> v;
	for (auto i = 0; i < s.size(); ++i)
		if (isdigit(s[i]))v.push_back(s[i] - '0');
	sort(v.begin(), v.end());
	for (auto i = 0; i < s.size(); ++i)
	{
		if (isdigit(s[i]))
		{
			int val = v.front();
			v.erase(v.begin());
			s[i] = '0' + val;
		}
	}
	cout << s << endl;

	return 0;
}