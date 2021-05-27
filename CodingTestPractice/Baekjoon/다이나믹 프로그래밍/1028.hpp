#include <iostream>
#include <string>
#include <vector>
using namespace std;


int R,C;
using vvi = vector<vector<int>>;
enum DIR {
	RD,LD,RU,LU
};

bool isInRange(int y, int x) {
	return 0 <= y && y < R && 0 <= x && x < C;
}

int makeDP(vector<string>& table, vvi& rddp, vvi& lddp,int r, int c, DIR dir) {
	if (!isInRange(r, c))return 0;
	if (table[r][c] == '0') return 0;
	switch (dir) {
	case RD:
		rddp[r][c] = makeDP(table, rddp, lddp,r + 1, c + 1, dir) + 1;
		return rddp[r][c];
	case LD:
		lddp[r][c] = makeDP(table, rddp, lddp,r + 1, c - 1, dir) + 1;
		return lddp[r][c];
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();

	vector<string> table(R);
	vvi rddp(R);
	vvi lddp(R);

	for (int i = 0; i < R; ++i) {
		rddp[i].resize(C);
		lddp[i].resize(C);

		getline(cin, table[i]);
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (table[i][j] == '1') {
				if (rddp[i][j] == 0)
					makeDP(table, rddp, lddp, i, j, RD);
				if (lddp[i][j] == 0)
					makeDP(table, rddp, lddp, i, j, LD);

			}
		}
	}
	int M = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (table[i][j] == '1') {
				int k = min(rddp[i][j], lddp[i][j]);
				if (k < M)continue;
				for (int len = 1; len <= k; ++len) {
					int ry = i + len-1, rx = j + len-1;
					int ly = i + len-1, lx = j - len+1;
					if (rddp[ly][lx] < len || lddp[ry][rx] < len)continue;

					int dy = ry + len - 1, dx = rx - len + 1;
					if (!isInRange(dy, dx))continue;
					M = (M < len) ? len : M;
				}
			}
		}
	}

	cout << M;

	return 0;
}