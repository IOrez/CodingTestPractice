#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int V, N;
	cin >> V >> N;
	vector<vector<int> > v(V+1);
	vector<int> degree(V + 1);
	vector<int>result;
	for (auto i = 1; i <= N; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}
	priority_queue<int> que;
	for (int i = 1; i <= V; ++i)
		if (degree[i] == 0)que.push(-i);

	for (int i = 1; i <= V; ++i)
	{
		if (que.empty())
		{
			cout << "-1";
			return 0;
		}

		auto x = -que.top();
		que.pop();
		result.push_back(x);
		for (auto val : v[x])
		{
			if (--degree[val] == 0)
				que.push(-val);
		}
	}
	for (auto val : result)
		cout << val << "\n";

	return 0;
}