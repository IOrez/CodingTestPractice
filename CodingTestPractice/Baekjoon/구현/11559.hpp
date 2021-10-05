#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

string table[12];
bool check[12][6];


bool IsInRange(int y, int x) {
	return 0 <= y && y < 12 && 0 <= x && x < 6;
}

void RePaint() {
	for (int i = 10; i >= 0; --i) {
		for (int j = 0; j <= 6; ++j) {
			int idx = i;
			if (table[idx][j] == '.')continue;
			while ((idx + 1) <= 11&&table[idx + 1][j] == '.') {
				table[idx + 1][j] = table[idx][j];
				table[idx][j] = '.';
				idx++;
			}
		}
	}
}


void DFS(vector<pair<int, int>>& v, int y, int x, char c) {
	if (!IsInRange(y, x))return;
	if (check[y][x])return;
	if (table[y][x] != c||table[y][x]=='.')return;

	check[y][x] = true;
	v.push_back({ y,x });
	for (int i = 0; i < 4; ++i)
		DFS(v, y + dy[i], x + dx[i], c);

}


void Calc(int i,int j,bool& result) {
	char c = table[i][j];
	vector<pair<int,int>> v;
	DFS(v, i, j, c);

	if (v.size() >= 4) {
		for (auto i : v)table[i.first][i.second] = '.';
		result = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int ans = 0;
	for (int i = 0; i < 12; ++i)
		getline(cin, table[i]);

	while (true) {
		memset(check, false, sizeof(check));
		bool result = false;
		for (int i = 11; i >= 0; --i) {
			for (int j = 0; j < 6; ++j) {
				Calc(i, j, result);
			}
		}

		if (result)ans++;
		else break;

		RePaint();
	}

	cout << ans;

	return 0;
}