#include <iostream>
#include <algorithm>
using namespace std;

#define MIN 987654321

int table[1][3];
int MAX_DP[2][3],MIN_DP[2][3];
int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < 3; ++i)MIN_DP[1][i] = MIN;
	for (int i = 0; i < N; ++i) {
		cin >> table[0][0] >> table[0][1] >> table[0][2];
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (j == 0 && k == 2)continue;
				if (j == 2 && k == 0)continue;
				MAX_DP[1][k] = max(MAX_DP[1][k], MAX_DP[0][j] + table[0][k]);
				MIN_DP[1][k] = min(MIN_DP[1][k], MIN_DP[0][j] + table[0][k]);
			}
		}
		for (int j = 0; j < 3; ++j) {
			MAX_DP[0][j] = MAX_DP[1][j];
			MIN_DP[0][j] = MIN_DP[1][j];
			MIN_DP[1][j] = MIN;
		}
	}

	int result_max = 0, result_min = MIN;
	for (int i = 0; i < 3; ++i) {
		result_max = max(result_max, MAX_DP[0][i]);
		result_min = min(result_min, MIN_DP[0][i]);
	}
	cout << result_max << " " << result_min;

	return 0;
}