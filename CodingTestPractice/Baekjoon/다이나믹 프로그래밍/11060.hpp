#include <iostream>
#include <queue>
using namespace std;

#define MAX 99999999

int DP[1001],N;
int Table[1001];

int solution() {
	for (int t = 2; t <= N; ++t)
		DP[t] = MAX;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int i = que.front();
		que.pop();
		int step = Table[i];
		for (int t = 1; t <= step; ++t) {
			int newIndex = i + t;
			if (newIndex > N)continue;
			if (DP[i] + 1 < DP[newIndex]) {
				DP[newIndex] = DP[i] + 1;
				que.push(newIndex);
			}
		}
	}
	return DP[N];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Table[i];
	int result = solution();
	if (result == MAX)result = -1;
	cout << result;
	return 0;
}