#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

enum type {
	UNKNOWN = -1,
	AIR,
	CHEEZE
};

using vvt = vector<vector<tuple<int,int,type>>>;
using qpii = queue<pair<int, int>>;
int N,M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void BFS(vvt& table, qpii& delq, int y, int x,int t, type groupid) {
	queue<tuple<int, int>> que;
	table[y][x] = { get<0>(table[y][x]),t,groupid };
	que.push({ y,x });
	while (!que.empty()) {
		auto [posy, posx] = que.front();
		que.pop();

		if (groupid == CHEEZE){
			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				int yy = posy + dy[i], xx = posx + dx[i];
				if (!isInRange(yy, xx))continue;
				if (get<2>(table[yy][xx]) == AIR)cnt++;
			}
			if (cnt >= 2)
				delq.push({ posy,posx });
		}

		for (int i = 0; i < 4; ++i) {
			int yy = posy + dy[i], xx = posx + dx[i];
			if (!isInRange(yy, xx) || get<0>(table[y][x]) != get<0>(table[yy][xx]))continue;
			if (get<2>(table[yy][xx]) != groupid|| get<1>(table[yy][xx])!=t) {
				get<2>(table[yy][xx]) = groupid;
				get<1>(table[yy][xx]) = t;
				que.push({ yy,xx});
			}
		}
	}
}

void Init(vvt& table, qpii& delq) {

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> get<0>(table[i][j]);
			get<1>(table[i][j]) = 0;
			get<2>(table[i][j]) = UNKNOWN;
		}

	for (int i = 0; i < N; ++i) {
		{
			auto [val, t, groupid] = table[i][0];
			if (val==0)
				BFS(table, delq, i, 0, t, AIR);
		}

		{
			auto [val, t, groupid] = table[i][M-1];
			if (val == 0)
				BFS(table, delq, i, M - 1, t, AIR);
		}
	}


	for (int i = 0; i < M; ++i) {
		{
			auto [val, t, groupid] = table[0][i];
			if (val == 0)
				BFS(table, delq, 0, i, t, AIR);
		}

		{
			auto [val, t, groupid] = table[N-1][i];
			if (val == 0)
				BFS(table, delq, N-1, i, t, AIR);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	vvt table(N, vector<tuple<int,int,type>>(M));
	qpii delq;

	Init(table, delq);
	int time = 0;
	while(true){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			auto [val, t, groupid] = table[i][j];
			if (val == 1 && (t != time+1 || groupid != CHEEZE))
				BFS(table, delq, i, j, time+1, CHEEZE);
		}
	}
	if (delq.empty())break;
	while (!delq.empty()) {
		auto [posy, posx] = delq.front();
		delq.pop();
		table[posy][posx] = { 0,0,AIR };

		for (int i = 0; i < 4; ++i){
			int yy = posy + dy[i], xx = posx + dx[i];
			if (!isInRange(yy, xx))continue;
			if (get<0>(table[yy][xx]) == 0 && get<2>(table[yy][xx]) == UNKNOWN)
				BFS(table, delq, yy, xx, 0, AIR);
		}
	}
	time++;
	}
	 cout << time;
	return 0;
}