#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool check[1001];

void dfs(vector<vector<int>>& table, int vertex)
{
	for (auto i : table[vertex])
		if (check[i])continue;
		else
		{
			check[i] = true;
			dfs(table, i);
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	vector<vector<int>> table(N+1);
	for (int i = 0;i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		table[s].push_back(e);
		table[e].push_back(s);
	}
	
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (check[i])continue;
		check[i] = true; cnt++;
		dfs(table,i);
	}

	cout << cnt;
	return 0;
}