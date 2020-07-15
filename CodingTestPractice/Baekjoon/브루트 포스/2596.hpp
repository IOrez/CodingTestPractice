#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
string output;

string table[8] = {
	"000000",
	"001111",
	"010011",
	"011100",
	"100110",
	"101001",
	"110101",
	"111010"
};
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	cin.ignore();
	getline(cin, input);
	for (int i = 0; i < input.size(); i += 6)
	{
		vector<char> v;
		bool check = false;
		for (int k = 0; k < 8; ++k)
		{
			int cnt = 0;
			for (int j = i; j < i + 6; ++j)
				if (table[k][j - i] != input[j])cnt++;
			if (cnt == 0)
			{
				check = true;
				output.push_back('A' + k);
				break;
			}
			else if (cnt == 1)v.push_back('A' + k);
		}
		if (!check && v.size() == 1)
			output.push_back(v[0]);
		else if (!check)
		{
			output.clear();
			output.push_back('1' + i / 6);
			break;
		}
	}
	cout << output;
}