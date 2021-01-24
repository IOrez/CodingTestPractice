#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_VERTEX	10001

int V, E;

vector<vector<pair<int,long long>>> edge(MAX_VERTEX);
priority_queue<tuple<int, int, int>> weight_list;
vector<bool> check(MAX_VERTEX);

long long solution(int v,int cnt) {
	long long result = 0;
	for (auto& i : edge[v])weight_list.push({ -i.second,v,i.first });
	check[v] = true;
	while (cnt != V - 1) {
		while (!weight_list.empty()) {
			auto[weight, v1, v2] = weight_list.top();
			weight_list.pop();
			if (check[v2])continue;
			weight *= -1;
			result += weight;
			check[v2] = true;
			v = v2;
			break;
		}
		cnt += 1;
		for (auto& i : edge[v])
			weight_list.push({ -i.second,v,i.first });
	}
	return result;
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		int s, e, w;
		cin >> s >> e >> w;
		edge[s].push_back({ e,w });
		edge[e].push_back({ s,w });
	}
	
	cout << solution(1, 0);
	return 0;
}