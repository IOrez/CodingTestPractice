#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
int table[10][10];
int Min = (1 << 31)-1;
bool visited[10];

void Floyd() {
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
}

void dfs(int vertex,int weight,int depth) {
	if (Min < weight)return;
	if (depth == N) {
		Min = min(Min, weight);
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (visited[i])continue;
		visited[i] = true;
		dfs(i,weight+table[vertex][i],depth+1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];
	Floyd();
	visited[K] = true;
	dfs(K, 0, 1);
	visited[K] = false;

	cout << Min;
	return 0;
}