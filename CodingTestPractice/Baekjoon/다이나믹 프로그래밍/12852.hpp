#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int dp[1000001];
int path[1000001];

int N;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		int minValue = 99999999;

		if (i % 3 == 0 && minValue > dp[i / 3])
		{
			minValue = dp[i / 3];
			path[i] = i / 3;
		}

		if (i % 2 == 0 && minValue > dp[i / 2])
		{
			minValue = dp[i / 2];
			path[i] = i / 2;
		}

		if (minValue > dp[i - 1])
		{
			minValue = dp[i - 1];
			path[i] = i - 1;
		}

		dp[i] = minValue + 1;
	}

	cout << dp[N]<<'\n';

	int i = N;
	while (i != 0)
	{
		cout << i << " ";
		i = path[i];
	}
}