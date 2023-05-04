#include <iostream>
#include <algorithm>

using namespace std;

int dp[201],N;
int arr[201];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (arr[j] < arr[i] && dp[j] + 1 >= dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		result = max(result, dp[i]);
	}

	result = N - result;
	cout << result;
}