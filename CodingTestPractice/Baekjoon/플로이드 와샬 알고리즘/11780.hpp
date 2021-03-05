#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int const MAXVAL = 999999;

int N, M;

int table[101][101];
int DP[101][101];

void path(vector<int>& v, int i, int j) {
	if (DP[i][j] == 0)return;
	path(v, i, DP[i][j]);
	v.push_back(DP[i][j]);
	path(v, DP[i][j], j);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (i == j)table[i][j] = 0;
			else table[i][j] = MAXVAL;


	int s, e, w;
	for (int i = 0; i < M; ++i) {
		cin >> s >> e >> w;
		if (table[s][e] > w)
			table[s][e] = w;
	}

	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j) {
				if (table[i][j] > table[i][k] + table[k][j]) {
					table[i][j] = table[i][k] + table[k][j];
					DP[i][j] = k;
				}
			}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (table[i][j] == MAXVAL)cout << 0 << ' ';
			else cout << table[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j || DP[i][j] == MAXVAL)cout << 0 << '\n';
			else {
				vector<int> v;
				path(v, i, j);
				cout << v.size() + 2 << ' ';
				cout << i << ' ';
				for (auto& k : v)
					cout << k << ' ';
				cout << j << '\n';
			}
		}
	}


	return 0;
}