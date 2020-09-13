#include <iostream>

using namespace std;

int DP[1025][1025];
int Table[1025][1025];
int N, M, x_1, x_2, y_1, y_2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			cin >> Table[i][j];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + Table[i][j];
		}
	}

	for (int i = 0; i < M; ++i) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cout << DP[x_2][y_2] - DP[x_2][y_1 - 1] - DP[x_1 - 1][y_2] + DP[x_1 - 1][y_1 - 1]<<'\n';
	}
	return 0;
}