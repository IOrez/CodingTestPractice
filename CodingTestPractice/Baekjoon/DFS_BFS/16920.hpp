#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#define WALL		-1
#define EMPTY		 0

#pragma warning(disable:4996)

using namespace std;
int N, M, PlayerNumber;

queue<tuple<int, int,int>> que[10];
bool flag;
vector<int>	s(10);
string input;
int table[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int cnt[10];
bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void func(int y, int x, int step,int player,queue<tuple<int,int,int>>& eq) {
	for (int i = 0; i < 4; ++i) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (!isInRange(yy, xx))continue;
		if (table[yy][xx] != EMPTY)continue;
		table[yy][xx] = player;
		cnt[player]++;
		que[player].push({ yy,xx,s[player] });
		eq.push({ yy,xx,step - 1 });
		flag = true;
	}
}
void sol() {
	while (true) {
		flag = false;
		for (int i = 1; i <= PlayerNumber; ++i) {
			auto eq = que[i];
			auto preSize = que[i].size();
			while (!eq.empty()) {
				auto [posy, posx,step] = eq.front();
				eq.pop();
				if (step == s[i])que[i].pop();
				if (step == 0)continue;
				func(posy, posx, step, i, eq);
			}
		}
		if (!flag)break;
	}
	for (int i = 1; i <= PlayerNumber; ++i)
		printf("%d ", cnt[i]);
}
int main(){
	scanf("%d %d %d", &N, &M, &PlayerNumber);
	for (int i = 1; i <= PlayerNumber; ++i)
		scanf("%d", &s[i]);
	getchar();
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j) {
			scanf("%1c", &table[i][j]);
			if (table[i][j] == '#')table[i][j] = WALL;
			else if (table[i][j] == '.')table[i][j] = EMPTY;
			else {
				int player = table[i][j] - '0';
				que[player].push({ i,j,s[player] });
				cnt[player]++;
				table[i][j] = player;
			}
		}
		getchar();
	}
	sol();
	return 0;
}