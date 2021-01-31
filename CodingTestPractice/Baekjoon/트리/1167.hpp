#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define SIZE	100001
#define START	1

using vpp = vector<vector<pair<int, int>>>;

bool check[SIZE];
int V,result;


int solution(vpp& a_table,int a_node) {
	int local_tot_result = 0;
	int local_result = 0;
	check[a_node] = true;
	priority_queue<int> each_weight;
	for (auto& i : a_table[a_node]) {
		auto [o_node, weight] = i;
		if (check[o_node])continue;
		int w = solution(a_table, o_node) + weight;
		local_result = max(w, local_result);
		each_weight.push(w);
	}

	if (!each_weight.empty()) {
		local_tot_result += each_weight.top();
		each_weight.pop();
		if (!each_weight.empty())
			local_tot_result += each_weight.top();

		result = max(result, local_tot_result);
	}

	return local_result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int node,o_node, weight;
	cin >> V;
	vpp table(V + 1);

	for (int i = 1; i <= V; ++i) {
		cin >> node;
		while (true) {
			cin >> o_node;
			if (o_node == -1)break;
			cin >> weight;
			table[node].push_back({ o_node,weight });
		}
	}
	solution(table, START);
	cout << result;
	return 0;
}