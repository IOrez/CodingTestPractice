#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, A, B,T, p1, p2;
	cin >> N;
	cin >> A >> B;
	cin >> T;
	vector<vector<int>> v(N+1, vector<int>());
	vector<bool> check(N + 1,false);
	while (T--) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	queue<pair<int,int>> que;
	check[A] = true;
	que.push({ A,0 });
	int result = -1;
	while (!que.empty()) {
		auto& [p, c] = que.front();
		que.pop();
		if (p == B) {
			result = c; break;
		}
		for (auto& i : v[p]) {
			if (check[i])continue;
			check[i] = true;
			que.push({ i,c + 1 });
		}
	}

	cout << result;
	return 0;
}