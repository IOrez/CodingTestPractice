#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

#define MAX_SIZE	50

#define HEDG		0
#define WATER		1
#define EMP			2
#define HALL		3
#define WALL		4

int R,C;
int Area[MAX_SIZE][MAX_SIZE];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool check[MAX_SIZE][MAX_SIZE][2];

queue<tuple<int, int, int>> wQue;
queue<tuple<int, int, int>> sQue;

bool isInRange(int y, int x) {
	return 0 <= y && y < R && 0 <= x && x < C;
}

int solution() {
	int result = -1;
	int step = 0;
	while (!sQue.empty()) {
		while (!wQue.empty() && std::get<2>(wQue.front()) != step) {
			auto [wy, wx, wstep] = wQue.front();
			wQue.pop();
			for (int i = 0; i < 4; ++i) {
				int dwy = wy + dy[i], dwx = wx + dx[i];
				if (!isInRange(dwy, dwx))continue;
				if (check[dwy][dwx][WATER]||Area[dwy][dwx]==HALL||Area[dwy][dwx]==WALL)continue;
				Area[dwy][dwx] = WATER;
				check[dwy][dwx][WATER] = true;
				wQue.push({ dwy,dwx,wstep + 1 });
			}
		}

		while (!sQue.empty() && std::get<2>(sQue.front()) != step) {
			auto [sy, sx, sstep] = sQue.front();
			sQue.pop();
			for (int i = 0; i < 4; ++i) {
				int dsy = sy + dy[i], dsx = sx + dx[i];
				if (!isInRange(dsy, dsx))continue;
				if (check[dsy][dsx][HEDG] || check[dsy][dsx][WATER]|| Area[dsy][dsx] == WALL)continue;
				if (Area[dsy][dsx] != HALL) {
					check[dsy][dsx][HEDG] = true;
					sQue.push({ dsy,dsx,sstep + 1 });
					continue;
				}
				result = sstep + 1;
				return result;
			}
		}
		step++;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> R >> C;

	for(int y =0;y<R;++y)
		for (int x = 0; x < C; ++x)
		{
			char ch;
			cin >> ch;
			switch (ch) {
			case 'S':Area[y][x] = HEDG; sQue.push({ y,x,0 }); check[y][x][HEDG] = true; break;
			case '*':Area[y][x] = WATER; wQue.push({ y,x,0 }); check[y][x][WATER] = true; break;
			case '.':Area[y][x] = EMP; break;
			case 'D':Area[y][x] = HALL; break;
			case 'X':Area[y][x] = WALL; break;
			}
		}

	int result = solution();
	if (result == -1)cout << "KAKTUS";
	else cout << result;

	return 0;
}