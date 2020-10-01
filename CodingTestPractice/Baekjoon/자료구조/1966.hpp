#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> que;
priority_queue<int> pq;
int testCase;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> testCase;
	while (testCase--) {
		int N, M,Num,M_pri;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			cin >> Num;
			if (i == M)M_pri = M;
			que.push({ i,Num });
			pq.push(Num);
		}
		int cnt = 0;
		while (!pq.empty()) {
			if (pq.top() == que.front().second) {
				cnt++;
				if (que.front().first == M)break;
				pq.pop();
				que.pop();
			}
			else {
				que.push(que.front());
				que.pop();
			}
		}
		cout << cnt << '\n';
		while (!pq.empty())pq.pop();
		while (!que.empty())que.pop();
	}
	return 0;
}