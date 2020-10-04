#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, r, p1, p2, w;

int table[101][101];
int items[101];

void Floyd() {
	for (int k = 1; k <= n; ++k) 
		for(int i=1;i<=n;++i)
			for (int j = 1; j <= n; ++j) {
				if (table[i][k] != -1 && table[k][j] != -1) {
					if (table[i][j] == -1)
						table[i][j] = table[i][k] + table[k][j];
					else
						table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
				}
			}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(table, -1, sizeof(table));
	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i) {
		table[i][i] = 0;
		cin >> items[i];
	}

	for (int i = 0; i < r; ++i) {
		cin >> p1 >> p2 >> w;
		table[p1][p2] = w;
		table[p2][p1] = w;
	}
	Floyd();

	int maxItems = 0;
	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (table[i][j] == -1)continue;
			if (table[i][j] <= m)
				cnt += items[j];
		}
		if (maxItems < cnt)maxItems = cnt;
	}
	cout << maxItems;
	return 0;
}