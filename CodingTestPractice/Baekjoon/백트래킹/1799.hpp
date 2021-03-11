#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> con[2], v;

bool table[100];
int check[100];
int N, ans[2], dy[4] = { -1,1,-1,1 }, dx[4] = { -1,1,1,-1 };



void update(int idx,int val) {
	int y = idx / N, x = idx % N;
	check[idx] += val;
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j < N; ++j) {
			int yy = y + j * dy[i];
			int xx = x + j * dx[i];
			if (0 <= yy && yy < N && 0 <= xx && xx < N) {
				check[yy * N + xx] += val;
			}
			else break;
		}
	}
}

void solution(bool flag,int idx) {
	for (int i = idx; i < con[flag].size(); ++i) {
		int j = con[flag][i];
		if (!check[j]) {
			update(j, 1);
			v.push_back(i);
			solution(flag, i + 1);
			ans[flag] = max(ans[flag], (int)v.size());
			v.pop_back();
			update(j, -1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		flag = !flag;
		bool b = flag;
		for (int j = 0; j < N; ++j) {
			int idx = i * N + j;
			cin >> table[idx];
			if (table[idx])con[b].push_back(idx);
			b = !b;
		}
	}

	solution(0, 0);
	solution(1, 0);
	cout << ans[0]+ans[1];
	return 0;
}