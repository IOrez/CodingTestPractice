#include <iostream>

using namespace std;
int N, K,DP[11][11];

int solution(int n, int k) {
	if (DP[n][k])return DP[n][k];
	if (k == 0 || k == n)return 1;
	DP[n][k] = solution(n - 1, k - 1) + solution(n - 1, k);
	return DP[n][k];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	cout << solution(N, K);
	return 0;
}