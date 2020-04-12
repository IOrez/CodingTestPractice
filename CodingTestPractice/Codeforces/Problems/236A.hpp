#include <iostream>
#include <string>
using namespace std;
constexpr int Size = 'z' - 'a';
bool charset[(Size + 1)];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); ++i)
		charset[s[i] - 'a'] = true;

	int cnt = 0;
	for (int i = 0; i <= Size; ++i)
		if (charset[i])cnt += 1;

	if (cnt % 2 != 0)cout << "IGNORE HIM!";
	else cout << "CHAT WITH HER!";

	return 0;
}