#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
int table[64];
int c_table[64];
int dy[4] = {0,0,1,-1};
int dx[4] = { 1,-1,0,0 };
bool check[64];

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}
int Max = -1;
queue<pair<int, int>> que;
vector<int> v;
void bfs(int y, int x) {
	check[y * M + x] = true;
	que.push({ y,x });
	while (!que.empty()) {
		auto [posy, posx] = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int yy = posy + dy[i], xx = posx + dx[i];
			if (!isInRange(yy, xx)||check[yy*M+xx])continue;
			if (c_table[yy * M + xx] == 0) {
				check[yy * M + xx] = true;
				c_table[yy * M + xx] = 2;
				que.push({ yy,xx });
			}
		}
	}
}
void solution(int yy, int xx) {
	if (v.size() == 3) {
		for (int i = 0; i < N * M; ++i)c_table[i] = table[i];
		memset(check, false, sizeof(check));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (c_table[i * M + j] == 2 && !check[i * M + j])
					bfs(i, j);

		int cnt = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (c_table[i * M + j] == 0)cnt++;
		if (Max < cnt)
			Max = cnt;
	}
	else {
		for(int i =yy*M+xx;i<N*M;++i)
			if (table[i] == 0) {
				table[i] = 1;
				v.push_back(i);
				solution(i / M, i % M);
				v.pop_back();
				table[i] = 0;
			}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < M; ++j)
			cin >> table[i * M + j];

	solution(0, 0);
	cout << Max;
	return 0;
}