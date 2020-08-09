#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits>
using namespace std;

int DP[501][501];
int sum[501];
int recurcive(int L, int R)
{
	if (DP[L][R] != 0)return DP[L][R];
	DP[L][R] = numeric_limits<int>::max();
	for (int i = L; i < R; ++i)
	{
		int s = sum[R] - sum[L - 1];
		DP[L][R] = min(DP[L][R],recurcive(L, i) + recurcive(i + 1, R) + s);
	}
	return DP[L][R];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase, N;
	cin >> testCase;
	while (testCase--)
	{
		cin >> N;
		memset(DP, 0, sizeof(DP));
		for (int i = 1; i <= N; ++i)
		{
			cin >> DP[i][i];
			sum[i] = sum[i - 1] + DP[i][i];
		}	
		cout << recurcive(1, N)-sum[N]<<'\n';
	}
	return 0;
}