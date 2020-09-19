#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


bool check[100][100];
char table[100][100];

int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool isInRange(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < N;
}

void bfs(int i, int j,bool t) {
	check[i][j] = true;
	queue<pair<int, int>> que;
	que.push({ i,j });
	while (!que.empty()) {
		auto& [y, x] = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int posy = y + dy[i];
			int posx = x + dx[i];
			if (!isInRange(posy, posx))continue;
			if (check[posy][posx])continue;
			if (t) {
				if (table[y][x] == 'B'&&table[y][x]!=table[posy][posx])continue;
				if (table[y][x] != 'B' && table[posy][posx] == 'B')continue;
			}
			else {
				if (table[y][x] != table[posy][posx])continue;
			}

			if (check[posy][posx])continue;
			check[posy][posx] = true;
			que.push({ posy,posx });
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N; cin.ignore();
	int cnt[2] = {0,0};

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];
		cin.ignore();
	}

	for (int t = 0; t < 2; ++t) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (!check[i][j]) {
					cnt[t]++;
					bfs(i, j, t);
				}
		cout << cnt[t] << " ";
	}


	return 0;
}