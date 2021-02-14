#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

using vvp = vector<vector<pair<int, int>>>;

#define SIZE 50
int N, L, R;

int table[SIZE][SIZE];
bool check[SIZE][SIZE];

int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

void bfs(int sy,int sx,vvp& a_vvp) {
	queue<pair<int, int>> que;
	que.push({ sy,sx });
	check[sy][sx] = true;
	a_vvp.push_back(vector<pair<int, int>>());
	a_vvp.back().push_back({ sy,sx });
	while (!que.empty()) {
		auto [y, x] = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int yy = y + dy[i], xx = x + dx[i];
			if (!isInRange(yy, xx)||check[yy][xx])continue;
			
			int dif = abs(table[yy][xx] - table[y][x]);
			if (dif >= L && dif <= R) {
				check[yy][xx] = true;
				a_vvp.back().push_back({ yy,xx });
				que.push({ yy,xx });
			}
		}
	}
	if (a_vvp.back().size()==1)a_vvp.pop_back();
	return;
}
int solution() {
	int Cnt = 0;
	while (true) {
		vvp v;
		memset(check, false, sizeof(check));
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (!check[y][x])
					bfs(y, x, v);
			}
		}

		for (auto& vp : v) {
			int Sum = 0;
			for (int i = 0; i < vp.size(); ++i) {
				auto [y, x] = vp[i];
				Sum += table[y][x];
			}
			int Avg = Sum / vp.size();
			for (int i = 0; i < vp.size(); ++i) {
				auto [y, x] = vp[i];
				table[y][x] = Avg;
			}
		}
		if (v.empty())break;
		Cnt++;
	}
	return Cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];

	cout << solution();

	return 0;
}