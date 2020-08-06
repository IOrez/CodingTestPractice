#include <iostream>
#include <cstring>
using namespace std;

bool DP[101];

int solution(int n)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; i * j <= n; ++j)
			DP[i*j] = !DP[i*j];
	int cnt = 0;
	for (int i = 1; i <= n; ++i)if (DP[i])cnt++;
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase,n; cin >> testCase;
	while (testCase--)
	{
		cin >> n; cout << solution(n) << '\n';
		memset(DP, 0, sizeof(DP));
	}

	return 0;
}