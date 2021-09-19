#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <optional>
using namespace std;

vector<string> table;
vector<vector<bool>> check;


int N, M;
int px, py;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
vector<char> keys;
char keytype;
optional<tuple<int, int, int>> key;

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

optional<tuple<int,int,int>> solution(int y, int x,int t) {
	queue<tuple<int,int,int>> que;
	check[y][x] = true;
	que.push({ y,x,t });
	while (!que.empty()) {
		auto [posy, posx,step] = que.front();
		que.pop();
		if (table[posy][posx] == '1')
			return tuple<int,int,int>{ posy,posx,step };
			
		bool result = false;
		if (table[posy][posx] >= 'A' && table[posy][posx] <= 'F') {
			for (auto key : keys) {
				if (toupper(key) == table[posy][posx]) {
					result = true;
					break;
				}
			}
			if (!result)continue;
			table[posy][posx] = '.';
		}
		else if (table[posy][posx] >= 'a' && table[posy][posx] <= 'f') {
			if (!key.has_value())
				key = tuple{ posy,posx,step };
		}

		for (int i = 0; i < 4; ++i) {
			int yy = posy + dy[i], xx = posx + dx[i];
			if (!isInRange(yy, xx) || check[yy][xx])continue;
			if (table[yy][xx] == '#')continue;
			check[yy][xx] = true;
			que.push({ yy,xx,step + 1 });
		}
	}
	return nullopt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	cin.ignore();
	table.resize(N);
	check.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, table[i]);
		for(int j =0;j<M;++j)
			if (table[i][j] == '0') {
				py = i,px = j;
			}
		check[i].resize(M);
	}

	int time = 0;
	while (true) {
		auto exitpos = solution(py, px, time);
		if (exitpos.has_value()) {
			cout << get<2>(exitpos.value());
			return 0;
		}
		else {
			if (key.has_value()) {
				table[py][px] = '.';
				auto [y, x, t] = key.value();
				py = y;
				px = x;
				keys.push_back(table[y][x]);
				table[py][px] = '0';
				key = nullopt;
				time = t;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				check[i][j] = false;
	}
	
	return 0;
}