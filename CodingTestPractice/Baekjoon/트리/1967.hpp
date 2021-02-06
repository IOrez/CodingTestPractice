#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define SIZE 10001
#define START 1

using vpp = vector<vector<pair<int, int>>>;

int N,v1,v2,weight,result;
vpp table(SIZE);
bool check[SIZE];

int solution(int n) {
	int cur_res = 0;
	check[n] = true;
	priority_queue<int> pq;
	for (auto i : table[n]) {
		auto [v, w] = i;
		if (check[v])continue;
		pq.push({ w + solution(v) });
	}
	if (!pq.empty()) {
		cur_res = pq.top(); 
		pq.pop();
		if (!pq.empty())
			result = max(result, cur_res + pq.top());
		result = max(result, cur_res);
	}
	return cur_res;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		cin >> v1 >> v2 >> weight;
		table[v1].push_back({ v2,weight });
		table[v2].push_back({ v1,weight });
	}
	solution(START);
	cout << result;
	return 0;
}