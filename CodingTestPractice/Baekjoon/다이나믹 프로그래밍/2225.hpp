#include <iostream>

using namespace std;
#define MOD 1000000000

int DP[201][201];

int solution(int n,int k)
{
	if (k < 0 || n < 0)return 0;
	if (n == 0)return 1;
	if (DP[n][k] != 0)return DP[n][k];
	for (int i = 0; i <= n; ++i)
		DP[n][k] = (solution(n - i, k - 1) + DP[n][k]) % MOD;

	return DP[n][k];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin >> N >> K;

	cout << solution(N, K);

	return 0;
}