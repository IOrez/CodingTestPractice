#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, a = 0, d = 0;
	string input;
	cin >> n; cin.ignore();
	getline(cin, input);
	for (auto& c : input)
	{
		if (c == 'A')a++;
		else if (c == 'D')d++;
	}

	if (a < d)cout << "Danik";
	else if (a == d)cout << "Friendship";
	else cout << "Anton";
	return 0;
}