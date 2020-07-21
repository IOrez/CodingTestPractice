#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string input;
string output[3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	getline(cin, input);
	sort(input.begin(), input.end());
	for(int i = 0;i<input.size();)
		if (i + 1 < input.size())
		{
			if (input[i] == input[i + 1])
			{
				output[0].push_back(input[i]);
				output[2].insert(output[2].begin(),input[i+1]);
				i += 2;
			}
			else
			{
				output[1].push_back(input[i]);
				i += 1;
			}
		}
		else
		{
			output[1].push_back(input[i]);
			i += 1;
		}
	if (output[1].size() > 1)
		cout << "I'm Sorry Hansoo";
	else
		for (int i = 0; i < 3; ++i)
			cout << output[i];
	return 0;
}