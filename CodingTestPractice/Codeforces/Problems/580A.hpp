#include <iostream>

using namespace std;

int DP[100000];
int table[100000];
int solution(int n)
{
	DP[0] = 1;
	int Max = DP[0];
	for (int i = 1; i < n; ++i)
	{
		DP[i] = 1;
		if (table[i - 1] <= table[i])DP[i] += DP[i - 1];
		if (Max < DP[i])Max = DP[i];
	}
	return Max;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> table[i];
	cout << solution(n);

	return 0;
}