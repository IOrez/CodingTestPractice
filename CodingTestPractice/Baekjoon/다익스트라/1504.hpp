#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[801];
bool check[801];
int  cost[801];
int N, M;

void init(int start)
{
	memset(cost, -1, sizeof(int) * 801);
	memset(check, 0, sizeof(bool) * 801);
	check[start] = true;
	cost[start] = 0;
	for (auto iter = v[start].begin(); iter != v[start].end(); iter++)
	{
		int node = iter->first;
		cost[node] = iter->second;
	}
}

void dijkstra(int start)
{
	init(start);
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (i == start)
			continue;
		if (check[i] == true)
			continue;
		if (cost[i] == -1)
			continue;

		pq.push(make_pair(-cost[i], i));
	}

	while (!pq.empty())
	{
		auto obj = pq.top();
		pq.pop();

		int n = obj.second;

		check[n] = true;

		for (auto iter = v[n].begin(); iter != v[n].end(); iter++)
		{
			int nn = iter->first;
			int nc = iter->second;

			if (check[nn] == true)
				continue;

			if (cost[nn] > cost[n] + nc || cost[nn] == -1)
			{
				cost[nn] = cost[n] + nc;
				pq.push(make_pair(-cost[nn], nn));
			}
		}
	}
}

int e[801][801];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	int a, b, edge ,c, d;
	int ans = 0;

	memset(e, -1, sizeof(int) * 801 * 801);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> edge;
		v[a].push_back(make_pair(b, edge));
		v[b].push_back(make_pair(a, edge));

		e[a][b] = edge;
		e[b][a] = edge;
	}
	cin >> c >> d;

	for (int i = 1; i <= N; i++)
		e[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				if (e[i][k] == -1 || e[k][j] == -1)
					continue;

				if (e[i][j] == -1 || e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}

	int a_c_cost, a_d_cost, c_d_cost, c_n_cost, d_n_cost;
	//dijkstra(c);
	c_d_cost = e[c][d];
	//dijkstra(1);
	a_c_cost = e[1][c];
	a_d_cost = e[1][d];
	//dijkstra(N);
	c_n_cost = e[c][N];
	d_n_cost = e[d][N];

	if (c_d_cost == -1)
		ans = -1;
	else
	{
		if ((a_c_cost == -1 || d_n_cost == -1) && (a_d_cost == -1 || c_n_cost == -1))
			ans = -1;
		else
		{
			ans = numeric_limits<int>::max();
			if ((a_c_cost != -1 && d_n_cost != -1))
			{
				ans = min(ans, a_c_cost + c_d_cost + d_n_cost);
			}

			if ((a_d_cost != -1 && c_n_cost != -1))
			{
				ans = min(ans, a_d_cost + c_d_cost + c_n_cost);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}