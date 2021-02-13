#include <iostream>
#include <cstring>
#include <queue>
#include <limits>
#include <tuple>
using namespace std;

#define SIZE 20

int N;

int table[SIZE][SIZE],startY,startX,scale = 2,cnt;
int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };
bool check[SIZE][SIZE];

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

tuple<int,int,int> solution() {
	queue<tuple<int, int,int>> que;
	memset(check, false, sizeof(check));
	check[startY][startX] = true;
	table[startY][startX] = 0;
	int bound = 0,by = -1, bx = -1;
	tuple<int, int, int> result = { startY,startX,bound };
	que.push(result);
	while (!que.empty()) {
		auto [y, x, t] = que.front();
		que.pop();
		if (bound != 0 && bound <= t)break;
		for (int i = 0; i < 4; ++i) {
			int yy = y + dy[i], xx = x + dx[i];
			if (!isInRange(yy, xx))continue;
			if (check[yy][xx]||table[yy][xx] > scale)continue;
			else {
				check[yy][xx] = true;
				if (table[yy][xx] < scale&& table[yy][xx] != 0) {
					if (bound == 0) {
						bound = t + 1;
						by = yy, bx = xx;
					}
					else if (by > yy || by == yy && bx > xx) {
						by = yy; bx = xx;
					}
					continue;
				}
				que.push({ yy,xx,t + 1 });
			}
		}
	}
	result = { by,bx,bound };
	table[by][bx] = 9;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			if (table[i][j] == 9) { startY = i; startX = j; }
		}

	int ans = 0;
	while (true) {
		auto [y, x, t] = solution();
		if (t == 0)break;
		else cnt++;
		ans += t;
		if (cnt == scale) {
			scale++; cnt = 0;
		}
		startY = y, startX = x;
	}

	cout << ans;
	return 0;
}