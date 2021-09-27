#include <iostream>
#include <queue>
using namespace std;

bool check[100001];
int N, K;

bool IsInRange(int i) {
	return 0 <= i && i <= 100000;
}
int Search(queue<pair<int,int>>& que) {
	auto [i,cnt] = que.front();
	que.pop();
	if (i == K) return cnt;

	int v[3] = { i - 1,i + 1,2 * i };
	for (int i = 0; i < 3; ++i) {
		if (IsInRange(v[i])) {
			if (check[v[i]])continue;
			check[v[i]] = true;
			que.push({ v[i],cnt + 1 });
		}
	}

	return -1;
}
int solution() {
	int ans = -1;
	queue<pair<int, int>> que;
	que.push({ N,0 });
	while ((ans = Search(que)) < 0) {}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	cout << solution();

	return 0;
}