#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool visited[1001];
int	 group[1001];

int dfs(int V, vector<vector<int> >& vTable,int groupNumber)
{
	visited[V] = true;
	group[V] = groupNumber;
	int result = 0;
	for (auto i : vTable[V])
	{
		if (group[i] == groupNumber)
			result += 1;
		else if (!visited[i])
			result += dfs(i, vTable, groupNumber);
	}	
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		memset(group, false, sizeof(group));

		int N;
		cin >> N;
		vector<vector<int> > vTable(N + 1);
		for (int i = 1; i <= N; ++i)
		{
			int endV;
			cin >> endV;
			vTable[i].push_back(endV);
		}

		int cnt = 0;
		int groupNumber = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (visited[i])continue;
			cnt += dfs(i, vTable, ++groupNumber);
		}
		cout << cnt << endl;
	}
	return 0;
}