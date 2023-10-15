#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> Fail_func(string s)
{
	int n = s.size();
	vector<int> vFail(n);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = vFail[j - 1];

		if (s[i] == s[j])
			j++;

		vFail[i] = j;
	}
	return vFail;
}

int kmp(string s, string comp, vector<int>& vFail)
{
	int idx = -1;
	int n = s.size();
	int m = comp.size();
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != comp[j])
			j = vFail[j-1];

		if (s[i] == comp[j])
		{
			if (j == m - 1)
				return i - m + 1;
			else
				j++;
		}
	}

	return idx;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string input, comp;
	getline(cin, input);
	getline(cin, comp);

	vector<int> vFail = Fail_func(comp);
	int idx = -1;
	do {
		idx = -1;
		idx = kmp(input, comp, vFail);
		if (idx != -1)
		{
			string prefix = input.substr(0, idx);
			string postfix = input.substr(idx + comp.size());

		}
	} while (idx != -1);

	if (input.size() == 0)
		cout << "FRULA";
	else
		cout << input;

	return 0;
}