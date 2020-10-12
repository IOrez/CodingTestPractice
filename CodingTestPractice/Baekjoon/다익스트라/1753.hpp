#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//1753
int V, E, K, Start, End, Weight;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> V >> E;
	cin >> K;
	vector<vector<pair<int,int>>> vTable(V + 1);
	vector<int> vDis(V + 1,-1);
	vector<bool> vCheck(V + 1,false);
	for (int i = 0; i < E; ++i) {
		cin >> Start >> End >> Weight;
		vTable[Start].push_back({ End,Weight });
	}
	vCheck[K] = true;
	vDis[K] = 0;
	for (auto& obj : vTable[K])
		if(vDis[obj.first]==-1|| vDis[obj.first] > obj.second)
			vDis[obj.first] = obj.second;

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= V; ++i)
		if (vDis[i] != -1 && i != K)pq.push({ -vDis[i],i });
	while (!pq.empty()) {
		auto [MinVal, pos] = pq.top();
		MinVal *= -1;
		pq.pop();
		if (MinVal > vDis[pos])continue;
		vCheck[pos] = true;
		for (auto& obj : vTable[pos]) {
			if (vCheck[obj.first])continue;
			if (vDis[obj.first] == -1 || vDis[obj.first] > vDis[pos] + obj.second)
			{
				vDis[obj.first] = vDis[pos] + obj.second;
				pq.push({ -vDis[obj.first],obj.first });
			}
		}

	}
	for (int i = 1; i <= V;++i) {
		if (vDis[i] == -1)
			cout << "INF" << '\n';
		else
			cout << vDis[i] << '\n';
	}
	return 0;
}