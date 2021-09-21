#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define MAX_VALUE 10001

int n, m, a, b, c;
int group[1000];
int table[1000][1000];

priority_queue<tuple<int, int, int>> pq;

void Init() {
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j)
			table[i][j] = MAX_VALUE;

	for (int i = 0; i < 1000; ++i)
		group[i] = i;
}

int FindGroup(int a) {
	if (group[a] == a)return group[a];
	return group[a] = FindGroup(group[a]);
}

bool CheckSameGroup(int a, int b) {
	int group_a = FindGroup(a);
	int group_b = FindGroup(b);

	return group_a == group_b;
}

void UnionFind(int a, int b) {
	int group_a = FindGroup(a);
	int group_b = FindGroup(b);

	if (group_a < group_b)group[group_b] = group_a;
	else group[group_a] = group_b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	Init();

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		a -= 1;
		b -= 1;
		if (table[a][b] > c) {
			table[a][b] = c;
			table[b][a] = c;
		}
	}

	for (int i = 0; i < 1000; ++i)
		for (int j = i; j < 1000; ++j)
			pq.push({ -table[i][j],i,j });
		
	int edges = 0;
	int cost = 0;
	while (!pq.empty() && edges + 1 != n) {
		auto [value, a, b] = pq.top();
		pq.pop();
		value = -value;

		bool isSameGroup = CheckSameGroup(a, b);
		if (isSameGroup)continue;
		UnionFind(a, b);
		cost += value;
		edges++;
	}
	cout << cost;
	return 0;
}