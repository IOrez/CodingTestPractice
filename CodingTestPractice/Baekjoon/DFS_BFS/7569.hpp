#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int table[100][100][100];
bool check[100][100][100];
int dh[2] = { -1,1 };
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int H, N, M;

bool isInRange( int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
queue<tuple<int, int, int,int>> que;

int bfs() {
	int m_day = 0;
	while (!que.empty()) {
		auto [h, y, x, day] = que.front();
		que.pop();
		if (day > m_day)m_day = day;
		for (int t = 0; t < 4; ++t) {
			int posy = y + dy[t], posx = x + dx[t];
			if (!isInRange(posy, posx))continue;
			if (check[h][posy][posx] || table[h][posy][posx] == -1)continue;
			check[h][posy][posx] = true;
			table[h][posy][posx] = 1;
			que.push({ h,posy,posx,day + 1 });
		}
		for (int t = 0; t < 2; ++t) {
			int layer = h + dh[t];
			if (0 > layer || layer >= H)continue;
			if (check[layer][y][x] || table[layer][y][x] == -1)continue;
			check[layer][y][x] = true;
			table[layer][y][x] = 1;
			que.push({ layer,y,x,day + 1 });
		}
	}
	return m_day;
}
bool isInRange(int h, int y, int x) {
	return 0 <= h && h < H && 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> M >> N >> H;
	for (int h = 0; h < H; ++h) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				cin >> table[h][y][x];
				if (table[h][y][x] == 1) {
					check[h][y][x] = true;
					que.push({ h,y,x,0});
				}
			}
		}
	}
	int result = bfs();
	bool c = true;
	for (int h = 0; h < H&&c; ++h)
		for (int y = 0; y < N&&c; ++y)
			for (int x = 0; x < M&&c; ++x) {
				c = (table[h][y][x] == 1 || table[h][y][x] == -1);
			}
	if (!c)result = -1;
	cout << result;
	return 0;
}