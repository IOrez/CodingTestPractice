#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
using vv = vector<vector<int>>;
int N, K, X, Y, W;

int IAC[1001], DP[1001];



int solution(queue<int>& que, vv& v,vv& ia) {
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		int MAX = 0;
		for (auto& i : ia[x])
			MAX = max({ MAX, DP[i] });
		DP[x] += MAX;
		if (x == W)break;
		for (auto& i : v[x]) {
			IAC[i]--;
			if (IAC[i] == 0)que.push(i);
		}
	}
	return DP[W];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase; cin >> testCase;
	while (testCase--) {
		memset(IAC, 0, sizeof(IAC));
		memset(DP, 0, sizeof(DP));
		cin >> N >> K;
		vv v(N + 1);
		vv ia(N + 1);
		for (int i = 1; i <= N; ++i)
			cin >> DP[i];
		for (int i = 1; i <= K; ++i) {
			cin >> X >> Y;
			IAC[Y]++;
			v[X].push_back(Y);
			ia[Y].push_back(X);
		}
		cin >> W;
		int MIN = 0xffff;
		vector<int> minV;
		for (int i = 1; i <= N; ++i) {
			if (MIN < IAC[i])continue;
			else if (MIN > IAC[i]) {
				minV.clear();
				MIN = IAC[i];
			}
			minV.push_back(i);
		}

		queue<int> que;
		for (auto& i : minV)
			que.push(i);

		cout << solution(que,v, ia)<<'\n';
	}

	return 0;
}