#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int cnt = 0;
	char ch = s[0];
	for (int i = 1; i < n; ++i)
	{
		if (ch == s[i]) cnt++;
		else  ch = s[i];
	}
	cout << cnt;
	return 0;
}