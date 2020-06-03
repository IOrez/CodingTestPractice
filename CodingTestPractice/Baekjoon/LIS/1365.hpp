#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int table[100000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)cin >> table[i];
	vector<int> v;
	v.push_back(table[0]);
	
	for (int i = 1; i < N; ++i)
	{
		if (v.back() < table[i])v.push_back(table[i]);
		else
		{
			auto iter = lower_bound(v.begin(), v.end(), table[i]);
			*iter = table[i];
		}
	}
	cout << N - v.size();
	return 0;
}