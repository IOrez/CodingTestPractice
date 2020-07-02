#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	getline(cin, input);
	int cnt = 0;
	for (auto& ch : input)if (ch == '4' || ch == '7')cnt++;
	if (cnt == 4 || cnt == 7)cout << "YES";
	else cout << "NO";

	return 0;
}