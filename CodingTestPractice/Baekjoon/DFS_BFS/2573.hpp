#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using qp = queue<pair<int, int>>;

int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,1,-1 };
bool bfs(qp& a_que, vvi& table, vvb& check, int N, int M);

bool isInRange(int y, int x, int N, int M) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void copy_table(vvi& dst, vvi const& src) {
	for (size_t i = 0; i < dst.size(); ++i)
		copy(src[i].begin(), src[i].end(), dst[i].begin());
}

int update(qp& a_que,vvi const& ctable, vvi& table, vvb& check,int N,int M) {

	qp que;
	for (size_t i = 0; i < N; ++i)
		for (size_t j = 0; j < M; ++j) {
			check[i][j] = false;
			if (table[i][j]) {
				a_que.push({ i,j });
				que.push({ i,j });
			}
		}

	if (bfs(a_que, table, check, N, M))return 0;
	if (que.empty())return -1;
	while (!que.empty()) {
		auto [y, x] = que.front();
		que.pop();
		int cnt = 0;
		for (int i = 0; i < 4; ++i) {
			int yy = y + dy[i], xx = x + dx[i];
			if (isInRange(yy, xx, N, M)&&!ctable[yy][xx])
				cnt++;
		}
		table[y][x] = table[y][x] - cnt < 0 ? 0 : table[y][x] - cnt;
		if (table[y][x])a_que.push({y,x});
	}
	return 1;
}


bool bfs(qp& a_que, vvi& table, vvb& check, int N, int M) {
	qp que;
	bool res = false, flag = false;
	while (!a_que.empty()) {
		auto [y, x] = a_que.front();
		a_que.pop();
		if (check[y][x])continue;
		if (flag) {
			res = true;
			break;
		}
		flag = true;
		que.push({ y,x });
		check[y][x] = true;
		while (!que.empty()) {
			auto [y, x] = que.front();
			que.pop();
			for (int i = 0; i < 4; ++i) {
				int yy = y + dy[i], xx = x + dx[i];
				if (isInRange(yy, xx, N, M) && !check[yy][xx]&&table[yy][xx]) {
					check[yy][xx] = true;
					que.push({ yy,xx });
				}
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	size_t N, M;
	cin >> N >> M;

	vvi table(N),ctable(N);
	vvb check(N);

	for (int i = 0; i < N; ++i) {
		table[i].resize(M);
		ctable[i].resize(M);
		check[i].resize(M);
		for (int j = 0; j < M; ++j) {
			cin >> table[i][j];
			ctable[i][j] = table[i][j];
		}
	}

	int ans = 0;
	while (true) {
		qp que;
		copy_table(ctable, table);
		int res = update(que, ctable, table, check, N, M);
		if (res == -1) {
			ans = 0; break;
		}
		else if (res == 0)break;
		ans++;
	}
	cout << ans;
	return 0;
}