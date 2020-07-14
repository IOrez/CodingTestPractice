#include <iostream>

using namespace std;

unsigned long long DP[31][31];

unsigned long long solution(int n, int r)
{
	if (n < r)return 0;
	DP[n][0] = DP[n][n] = 1;
	if (DP[n][r] != 0)return DP[n][r];
	DP[n][r] = solution(n - 1, r - 1) + solution(n - 1, r);
	return DP[n][r];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, r;
	cin >> n >> r;
	cout << solution(n, r);
	return 0;
}