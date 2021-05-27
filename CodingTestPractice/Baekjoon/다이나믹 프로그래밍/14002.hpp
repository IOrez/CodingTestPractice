#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;


void print(int i,vector<int>& parent,vector<int>& v) {
	if (parent[i] != i)
		print(parent[i], parent,v);
	cout << v[i] << " ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<int> v(N);
	vector<int> dp(N);
	vector<int> parent(N);

	for (auto& i : v)cin >> i;
	for (int i = 0; i < N; ++i) {
		int tidx = i;
		int len = 1;
		for (int j = 0; j < i; ++j) {
			if (v[j]<v[i] && dp[j] + 1>len) {
				tidx = j;
				len = dp[j] + 1;
			}
		}
		dp[i] = len;
		parent[i] = tidx;
	}
	int maxIdx = -1, maxVal = 0;
	for(int i =0;i<N;++i)
		if (maxVal < dp[i]) {
			maxIdx = i;
			maxVal = dp[i];
		}
	cout << maxVal << '\n';
	print(maxIdx, parent,v);

	return 0;
}