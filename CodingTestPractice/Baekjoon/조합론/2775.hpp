#include <iostream>

using namespace std;
int DP[15][15], k, n;
void init() {
	for (int i = 1; i < 15; ++i)
		DP[0][i] = i;
	for (int i = 1; i < 15; ++i) 
		for (int j = 1; j < 15; ++j)
			for (int k = 1; k <= j; ++k)
				DP[i][j] += DP[i - 1][k];
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase; cin >> testCase;
	init();
	while (testCase--) {
		cin >> k;
		cin >> n;
		cout << DP[k][n] << '\n';
	}
	return 0;
}