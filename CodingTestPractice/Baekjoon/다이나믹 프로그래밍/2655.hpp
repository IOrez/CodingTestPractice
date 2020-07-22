#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

#define INF 999999999
bool check[102];
vector<vector<pair<int, int>>> wGraph(102);
vector<tuple<int, int, int>> table(102);
list<int> ts;
int N, dp[102],p[102];

void dfs(int vertex)
{
	for (auto i : wGraph[vertex])
		if (check[i.first])continue;
		else
		{
			check[i.first] = true;
			dfs(i.first);
		}
	ts.insert(ts.begin(), vertex);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	table[0] = { INF,0,INF };
	table[N + 1] = { 0,0,0 };
	memset(p, -1, sizeof(p));
	int area, height, weight;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> area >> height >> weight;
		table[i] = { area,height,weight };
	}

	for (int i = 0; i <= N; ++i)
	{
		auto& [i_area, i_height, i_weight] = table[i];
		for (int j = 1; j <= N+1; ++j)
			if (i == j)continue;
			else
			{
				auto& [j_area, j_height, j_weight] = table[j];
				if (i_area >= j_area && i_weight >= j_weight)
					wGraph[i].push_back({ j,i_height });
			}
	}
	for (int i = 1; i <= N; ++i)
		sort(wGraph[i].begin(), wGraph[i].end());

	dfs(0);
	for (auto i : ts)
		for (auto j : wGraph[i])
			if (dp[j.first] < dp[i] + j.second)
			{
				dp[j.first] = dp[i] + j.second;
				p[j.first] = i;
			}
	
	int idx = N + 1;
	vector<int> v;
	while (p[idx] != -1)
	{
		v.push_back(p[idx]);
		idx = p[idx];
	}
	cout << v.size() << '\n';
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << '\n';
	return 0;
}