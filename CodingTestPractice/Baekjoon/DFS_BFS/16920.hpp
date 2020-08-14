#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define WALL		-1
#define EMPTY		 0
using namespace std;
int N, M, PlayerNumber;

queue<pair<int, int>> que[10];
queue<pair<int, int>> eq;
vector<int>	s(10);
string input;
int table[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int cnt[10];
bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void dfs(int y, int x, int& cnt,int player) {
	if (!isInRange(y, x)||cnt==0)return;
	else if (table[y][x] != EMPTY)return;
	else if (table[y][x] == EMPTY||table[y][x]==player) {
		if (table[y][x] == EMPTY) {
			cnt--;
			table[y][x] = player;
			eq.push({ y,x });
		}
		for (int i = 0; i < 4 && cnt != 0; ++i) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			dfs(yy, xx,cnt, player);
		}
	}
}
void sol() {
	while (true) {
		bool check = true;
		for (int i = 1; i <= PlayerNumber && check; ++i)
			check = que[i].empty();
		if (check)break;
		for (int i = 1; i <= PlayerNumber; ++i) {
			if (que[i].empty())continue;
			while (!que[i].empty()) {
				auto& [posy, posx] = que[i].front();
				que[i].pop();
				for (int t = 0; t < 4; ++ t) {
					int yy = posy + dy[t];
					int xx = posx + dx[t];
					int step = s[i];
					dfs(yy, xx, step, i);
				}
			}
			while (!eq.empty()) {
				que[i].push(eq.front());
				eq.pop();
			}
		}
	}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (table[i][j] == WALL || table[i][j] == EMPTY)continue;
			else cnt[table[i][j]]++;

	for (int i = 1; i <= PlayerNumber; ++i)
		cout << cnt[i] << " ";
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> PlayerNumber;
	for (int i = 1; i <= PlayerNumber; ++i)
		cin >> s[i];
	cin.ignore();
	int WallCnt = 0;
	for (int i = 0; i < N; ++i){
		getline(cin, input);
		for (int j = 0; j < M; ++j) {
			if (input[j] == '#')table[i][j] = WALL;
			else if (input[j] == '.')table[i][j] = EMPTY;
			else {
				int player = input[j] - '0';
				que[player].push({ i,j });
				table[i][j] = player;
			}
		}
	}

	sol();
	return 0;
}