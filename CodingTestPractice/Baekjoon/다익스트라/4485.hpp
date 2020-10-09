#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N,test;
int table[125][125];
bool check[125][125];
int DP[125][125];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

int Dijkstra(int y,int x) {
	DP[y][x] = table[y][x];
	while (true) {
		int Min = (1 << 31) - 1;
		int posy, posx;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (DP[i][j] != -1&&!check[i][j]&& DP[i][j] < Min) {
					Min = DP[i][j];
					posy = i; posx = j;
				}
		if (posy == N - 1 && posx == N - 1)break;
		check[posy][posx] = true;
		for (int i = 0; i < 4; ++i) {
			int xx = posx + dx[i], yy = posy + dy[i];
			if (!isInRange(yy, xx))continue;
			if (DP[yy][xx] == -1)
				DP[yy][xx] = DP[posy][posx] + table[yy][xx];
			else
				DP[yy][xx] = min(DP[yy][xx],DP[posy][posx] + table[yy][xx]);
		}
	}
	return DP[N - 1][N - 1];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int test = 0;
	while(true){
		cin >> N;
		if (N == 0)break;
		memset(DP, -1, sizeof(DP));
		memset(check, false, sizeof(check));

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> table[i][j];
	
		cout << "Problem "<<++test<<": " <<Dijkstra(0, 0)<<"\n";
	}

	return 0;
}