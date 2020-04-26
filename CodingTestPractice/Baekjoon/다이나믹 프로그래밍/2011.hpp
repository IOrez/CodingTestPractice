#include <iostream>
#include <string>
using namespace std;

#define MOD 1000000
int DP[5000];


bool solution(string& input)
{
	DP[0] = 1;
	if (input[1] == '0')return 0;
	DP[1] = 1;
	for (int i = 2; i < input.size(); ++i)
	{
		if (input[i] == '0')
		{
			if (input[i - 1] != '1' && input[i - 1] != '2')return false;
			DP[i] = DP[i - 2];
		}
		else
		{
			if (input[i - 1] == '2'&&input[i]<='6')
			{
				DP[i] = (DP[i] + DP[i - 2]) % MOD;
			}
			else if (input[i - 1] == '0')
			{
				if (i - 3 < 0)return false;
				DP[i] = (DP[i] + DP[i - 3]) % MOD;
				continue;
			}
			else if (input[i - 1] <= '1')
			{
				DP[i] = (DP[i] + DP[i - 2]) % MOD;
			}
			DP[i] = (DP[i] + DP[i - 1]) % MOD;
		}
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string input;
	cin >> input;
	input.insert(input.begin(), ' ');
	bool isCheck = solution(input);
	if (isCheck)cout << DP[input.size() - 1];
	else cout << 0;

	return 0;
}