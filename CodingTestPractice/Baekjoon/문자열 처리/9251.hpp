#include <iostream>
#include <string>
using namespace std;

int DP[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
	string input, comp;
	getline(cin, input);
	getline(cin, comp);

	input.insert(input.begin(), ' ');
	comp.insert(comp.begin(), ' ');
	
	
	for (int i = 1; i < input.size(); i++)
	{
		for (int j = 1; j < comp.size(); j++)
		{
			if (input[i] == comp[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	cout << DP[input.size()-1][comp.size()-1];
	return 0;
}