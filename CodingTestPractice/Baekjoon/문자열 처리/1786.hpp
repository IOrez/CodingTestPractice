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

int RabinFingerPrint(string s, string comp,int idx)
{
	int value = 0;
	int i,n = s.size(), m = comp.size();

	if (idx + m-1 >= n)
		return -1;

	for (i = 0; i < m; i++)
	{
		value += (s[idx + i])* pow(2, (m - 1) - i);
	}
	

	return value;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string inputA, inputB;
	getline(cin, inputA);
	getline(cin, inputB);

	vector<int> vPos = kmp(inputA, inputB);
	vector<int> vOtherPos;
	/*
	cout << vPos.size() << '\n';
	for (auto i = 0; i < vPos.size(); i++)
	{
		cout << vPos[i] + 1 << ' ';
	}
	*/

	int inputAHashValue = RabinFingerPrint(inputA, inputB, 0);
	int inputBHashValue = RabinFingerPrint(inputB, inputB, 0);

	int n = inputA.size(), m = inputB.size();
	for (int i = 0; i <= n-m ; i++)
	{
		if (i != 0)
		{
			inputAHashValue = (inputAHashValue - (inputA[i-1]) * pow(2, m - 1))*2 + (inputA[i + m - 1]);
		}

		if (inputAHashValue == inputBHashValue)
		{
			bool check = true;
			for (int j = 0, k = i; j < m && k < n && check; j++, k++)
				check = inputA[k] == inputB[j];

			if (check == true)
				vOtherPos.push_back(i);
		}
	}

	cout << vOtherPos.size() << '\n';
	for (auto i = 0; i < vPos.size(); i++)
	{
		cout << vOtherPos[i] + 1 << ' ';
	}

	return 0;
}