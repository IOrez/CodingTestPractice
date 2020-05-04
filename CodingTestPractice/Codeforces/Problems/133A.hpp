#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string input;
	cin >> input;
	bool result = false;
	for (auto c : input)
		if (c == 'H' || c == 'Q' || c == '9')
		{
			result = true;
			break;
		}
	if (result)cout << "YES";
	else cout << "NO";

	return 0;
}