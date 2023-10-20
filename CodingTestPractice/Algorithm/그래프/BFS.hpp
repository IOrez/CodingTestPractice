#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

bool isVisited[1001];

void bfs(int V, vector<vector<int> >& vTable)
{
	isVisited[V] = true;
	queue<int> que;
	que.push(V);
	while (!que.empty())
	{
		int v = que.front();
		cout << v << " ";
		que.pop();
		for (auto i : vTable[v])
		{
			if (isVisited[i])continue;
			isVisited[i] = true;
			que.push(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	vector<vector<int> > vTable(N + 1);
	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		cin >> a >> b;
		vTable[a].push_back(b);
		vTable[b].push_back(a);
	}

	for (auto& v : vTable)
		sort(v.begin(), v.end());

	bfs(V, vTable);

	return 0;
}