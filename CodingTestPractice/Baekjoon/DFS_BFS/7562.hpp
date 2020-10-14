#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int test, N, startX, startY, endX, endY;
int dy[8] = { -1,-2,-1,-2, 1, 2, 1, 2 };
int dx[8] = { -2,-1, 2, 1,-2,-1, 2, 1 };
bool check[300][300];

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

int bfs() {
	queue<tuple<int, int, int>>que;
	que.push({ startY,startX,0 });
	while (!que.empty()) {
		auto [y, x, cnt] = que.front();
		que.pop();
		if (y == endY && x == endX)return cnt;
		for (int i = 0; i < 8; ++i) {
			int posy = y + dy[i], posx = x + dx[i];
			if (!isInRange(posy, posx))continue;
			if (check[posy][posx])continue;
			check[posy][posx] = true;
			que.push({ posy,posx,cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> test;
	while (test--) {
		memset(check, false, sizeof(check));
		cin >> N;
		cin >> startY >> startX;
		cin >> endY >> endX;
		cout << bfs()<<'\n';
	}
	return 0;
}