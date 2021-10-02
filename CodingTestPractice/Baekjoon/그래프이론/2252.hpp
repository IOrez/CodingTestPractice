#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;

int cnt[32001];
vector<int> v[32001];
queue<int> que;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	int A, B;
	for (int i = 0; i < M; ++i) {
		cin >> A >> B;
		v[A].push_back(B);
		cnt[B]++;
	}

	for (int i = 1; i <= N; ++i)
		if (cnt[i] == 0)que.push(i);

	while (!que.empty()) {
		int idx = que.front();
		cout << idx << " ";
		que.pop();
		for (auto i : v[idx])
			if ((--cnt[i]) == 0)que.push(i);
	}
	cout << '\n';

	return 0;
}