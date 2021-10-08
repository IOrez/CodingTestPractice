#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
int N, A, B;

int Table[501];
int DP[501][501];

int Solution() {
	for (int dia = 1; dia < N; ++dia) {
		for (int i = 1; i <= N - dia; ++i) {
			int k = i + dia;
			DP[i][k] = numeric_limits<int>::max();
			for (int j = i; j < k; ++j) {
				int val = DP[i][j] + DP[j + 1][k] + Table[i-1] * Table[j] * Table[k];
				DP[i][k] = min(DP[i][k], val);
			}
		}
	}
	for (int i = 1; i <= N; ++i)
		DP[i][i] = Table[i-1] * Table[i];
	return DP[1][N];
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Table[i] >> Table[i + 1];
	cout << Solution();
	return 0;
}