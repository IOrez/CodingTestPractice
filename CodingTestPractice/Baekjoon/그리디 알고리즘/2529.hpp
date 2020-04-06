#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool valid(const string& signs,vector<int>& v)
{
	for (auto i = 0; i < signs.size(); ++i)
	{
		if (signs[i] == '<' && v[i] > v[i + 1])
			return false;
		else if (signs[i] == '>' && v[i] < v[i + 1])
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string signs;
	vector<int> maxNum;
	vector<int> minNum;

	int n;
	cin >> n;
	for (auto i = 0; i < n;++i)
	{
		char temp;
		cin >> temp;
		signs += temp;
	}
	
	for (int i = 9; i >= 9 - n; --i)
		maxNum.push_back(i);
	for (int i = 0; i <= n; ++i)
		minNum.push_back(i);

	while (true)
	{
		if (valid(signs, maxNum))
			break;
		prev_permutation(maxNum.begin(), maxNum.end());
	}

	while (true)
	{
		if (valid(signs, minNum))
			break;
		next_permutation(minNum.begin(), minNum.end());
	}
	for (auto i = 0; i < maxNum.size(); ++i)
		cout << maxNum[i];
	cout << '\n';
	for (auto i = 0; i < minNum.size(); ++i)
		cout << minNum[i];
	cout << '\n';
	return 0;
}