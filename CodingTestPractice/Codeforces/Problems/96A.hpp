#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int count = 1;
	char ch = s[0];
	for (auto i = 1; i < s.size(); ++i)
	{
		if (ch == s[i])count++;
		else
		{
			ch = s[i];
			count = 1;
		}
		if (count >= 7)break;
	}
	if (count >= 7)cout << "YES";
	else cout << "NO";
	return 0;
}