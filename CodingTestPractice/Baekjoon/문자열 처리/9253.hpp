#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fail_func(vector<int>& vfail, string s)
{
	int n = s.size();
	vfail.resize(n);

	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = vfail[j - 1];

		if (s[i] == s[j])
			j++;

		vfail[i] = j;
	}
}

vector<int> kmp(string s, string comp, vector<int>& vfail)
{
	vector<int> vpos;
	int n = s.size();
	int m = comp.size();
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != comp[j])
			j = vfail[j - 1];

		if (s[i] == comp[j])
		{
			if (j == m - 1)
			{
				vpos.push_back(i - m + 1);
				j = vfail[j];
			}
			else
			{
				j++;
			}
		}
	}

	return vpos;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string inputA, inputB, inputC;

	getline(cin, inputA);
	getline(cin, inputB);
	getline(cin, inputC);

	vector<int> vfail;
	vector<int> vInputAPos, vInputBPos;

	fail_func(vfail, inputC);
	vInputAPos = kmp(inputA, inputC, vfail);
	vInputBPos = kmp(inputB, inputC, vfail);

	if (vInputAPos.empty() == false && vInputBPos.empty() == false)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}