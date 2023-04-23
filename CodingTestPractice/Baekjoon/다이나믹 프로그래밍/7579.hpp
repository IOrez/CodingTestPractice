#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int appMems[101], cost[101];
int dp[101][10001];
int sumCost;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		cin >> appMems[i];
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[i];
		sumCost += cost[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= sumCost; ++j)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + appMems[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sumCost; ++i)
	{
		if (dp[N][i] > 0 && dp[N][i] >= M)
		{
			cout << i;
			break;
		}
	}
		
	return 0;
}