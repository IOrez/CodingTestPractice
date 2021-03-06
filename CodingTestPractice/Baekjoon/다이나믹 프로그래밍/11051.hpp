#include <iostream>

using namespace std;

#define MOD	10007
int DP[1001][1001];

int combi(int n, int k) {
	if (DP[n][k] != 0)return DP[n][k];
	if (k == 0 || n == k)return 1;

	DP[n][k] = (combi(n - 1, k - 1) + combi(n - 1, k)) % MOD;
	return DP[n][k];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	cout << combi(N, K);
	return 0;
}