#include <iostream>
#include <cstring>
using namespace std;

char table[101][101];
unsigned int DP[100][100];
bool check[100][100];
int N, M;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };



bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

unsigned int solution() {
	
	DP[0][0] = 0;

	unsigned int minval;
	while (true) {
		minval = -1;
		int y, x;
		for(int i = 0;i<N;++i)
			for (int j = 0; j < M; ++j) {
				if (DP[i][j] < minval&& !check[i][j]) {
					minval = DP[i][j];
					y = i;
					x = j;
				}
			}
		if (y == N - 1 && x == M - 1)break;
		check[y][x] = true;
		for (int i = 0; i < 4; ++i) {
			int yy = y + dy[i], xx = x + dx[i];
			if (!isInRange(yy, xx)||check[yy][xx])continue;

			if (DP[yy][xx] > DP[y][x]) {
				DP[yy][xx] = minval;
				if (table[yy][xx] == '1') DP[yy][xx] += 1;
			}
		}
	}
	return minval;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(DP, -1, sizeof(DP));
	
	cin >> M >> N; cin.ignore();
	for (int i = 0; i < N; ++i)
		cin >> table[i];

	cout << solution();
	return 0;
}