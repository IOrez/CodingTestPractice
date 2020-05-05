#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[101];
int dfs(int V, vector<vector<int> >& vTable)
{
	int result = 1;
	visited[V] = true;
	for (auto i : vTable[V])
	{
		if (visited[i])continue;
		result += dfs(i, vTable);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	vector<vector<int> > vTable(N+1);
	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		cin >> a >> b;
		vTable[a].push_back(b);
		vTable[b].push_back(a);
	}
	for (auto& v : vTable)sort(v.begin(), v.end());
	cout << dfs(1, vTable)-1;

	return 0;
}