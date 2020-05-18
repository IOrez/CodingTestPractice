#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	vector<int> DP(1000);
	for (int i = 0; i < str1.size(); ++i)
	{
		char ch = str1[i];
		int max = 0;
		for (int j = 0; j < str2.size(); ++j)
		{
			if (max < DP[j])max = DP[j];
			else if (ch == str2[j]) DP[j] = max + 1;
		}
	}
	int max = 0;
	for (int i = 0; i < str2.size(); ++i)
		if (max < DP[i])max = DP[i];

	cout << max;
	return 0;
}