#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int test;
int N, M, K,Start,End,Time,Cost,MinTime;

using vti3 = vector<vector<tuple<int, int, int>>>;

int Dijkstra(vti3& vTable) {
	MinTime = (1 << 31) - 1;
	priority_queue<tuple<int,int,int>> pq;
	vector<vector<int>> vTime(N + 1, vector<int>(M + 1)); 
	pq.push({0,0,1 });
	while (!pq.empty()) {
		auto [cost,DP, pos] = pq.top();
		pq.pop();
		cost *= -1;
		if (vTime[pos][cost] < DP)continue;
		if (pos == N) {
			if (MinTime > DP)
				MinTime = DP;
		}
		else {
			int time = vTime[pos][cost];
			for (auto& obj : vTable[pos]) {
				auto [e, c, t] = obj;
				if (cost + c > M)continue;
				if (vTime[e][cost + c] > time + t || vTime[e][cost + c] == 0) {
					vTime[e][cost + c] = time + t;
					pq.push({ -(cost + c),time + t,e });
				}
			}
		}
	}
	return MinTime;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> test;
	while (test--) {
		cin >> N >> M >> K;
		vti3 vTable(N + 1);
		for (int i = 0; i < K; ++i) {
			cin >> Start >> End >> Cost >> Time;
			vTable[Start].push_back({ End,Cost,Time });
		}
		Dijkstra(vTable);
		if (MinTime == ((1 << 31) - 1)) { cout << "Poor KCM" << '\n'; }
		else cout << MinTime << '\n';
	}
	return 0;
}