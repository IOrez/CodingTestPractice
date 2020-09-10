#include <iostream>
using namespace std;
int DP[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		int num; cin >> num;
		DP[i] = DP[i - 1] + num;
	}
	while (M--) {
		int i, j; cin >> i >> j;
		cout << DP[j] - DP[i - 1]<<'\n';
	}
}