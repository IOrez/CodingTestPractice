#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> fail_func(string s)
{
	int n = s.size();
	vector<int> vfail(n);
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = vfail[j - 1];

		if (s[i] == s[j])
			j++;

		vfail[i] = j;
	}

	return vfail;
}

vector<int> kmp(string s, string comp)
{
	int n = s.size();
	int m = comp.size();
	vector<int> vfail = fail_func(comp);
	vector<int> vPos;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (j > 0 && s[i] != comp[j])
			j = vfail[j - 1];

		if (s[i] == comp[j])
		{
			if (j == m - 1)
			{
				vPos.push_back(i - m + 1);
				j = vfail[j];
			}
			else
			{
				j++;
			}
		}
	}

	return vPos;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string inputA, inputB;
	getline(cin, inputA);
	getline(cin, inputB);

	vector<int> vPos = kmp(inputA, inputB);

	cout << vPos.size() << '\n';
	for (auto i = 0; i < vPos.size(); i++)
	{
		cout << vPos[i] + 1 << ' ';
	}

	return 0;
}