#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> picked;
int table[9];

void solution(int n)
{
	if (picked.size() == 7)
	{
		int sum = 0;
		for (auto& i : picked)sum += i;
		if (sum == 100)
		{
			sort(picked.begin(), picked.end());
			for (auto& i : picked)cout << i << '\n';
			exit(0);
		}
	}
	else if (n < 9)
	{
		for (int i = n; i < 9; ++i)
		{
			picked.push_back(table[i]);
			solution(i + 1);
			picked.pop_back();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 9; ++i)cin >> table[i];
	solution(0);
	return 0;
}