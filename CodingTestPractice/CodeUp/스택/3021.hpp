#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input[2];
	string result;
	for (int i = 0; i < 2; ++i)
		getline(cin, input[i]);

	if (input[0].size() < input[1].size())
		while (input[0].size() != input[1].size())
			input[0].insert(input[0].begin(), '0');
	else if(input[0].size()>input[1].size())
		while (input[0].size() != input[1].size())
			input[1].insert(input[1].begin(), '0');

	bool C = false;
	for (int i = input[1].size() - 1; i >= 0; --i)
	{
		int iinput0 = input[0][i] - '0';
		int iinput1 = input[1][i] - '0';
		int sum = iinput0 + iinput1 + (int)C;
		if (sum >= 10)
		{
			C = true;
			sum -= 10;
		}
		else C = false;
		result.insert(result.begin(), (char)(sum + '0'));
	}
	if (C)
		result.insert(result.begin(), '1');
	cout << result;
	return 0;
}