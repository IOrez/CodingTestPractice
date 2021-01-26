#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 100001

int N;
int v1, v2;
vector<vector<int>> table(MAX_SIZE);
vector<int> parent(MAX_SIZE);

void solution(int root) {
	for (auto& i : table[root]) {
		if (i == parent[root])continue;
		parent[i] = root;
		solution(i);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;

	for (int i = 1; i <= N - 1; ++i) {
		cin >> v1 >> v2;
		table[v1].push_back(v2);
		table[v2].push_back(v1);
	}

	solution(1);
	for (int i = 2; i <= N; ++i)
		cout << parent[i] << '\n';


	return 0;
}