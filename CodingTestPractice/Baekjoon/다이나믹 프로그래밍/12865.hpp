#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K, W, V;
int  DP[100001];
vector<pair<int, int>> vTable;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> W >> V;
		vTable.push_back({ W,V });
	}

	for (int i = 0; i < N; ++i) {
		auto& [weight, value] = vTable[i];
		for (int j = K; j >= 0; --j) {
			if (j + weight > K)continue;
			DP[j + weight] = max(DP[j + weight], DP[j] + value);
		}
	}
	cout << *max_element(DP, DP + K + 1);
	return 0;
}