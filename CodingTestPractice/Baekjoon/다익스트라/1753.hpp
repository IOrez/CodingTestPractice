#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 999999

int table[20001][2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int V, E, S;
	cin >> V >> E;
	cin >> S;
	priority_queue<pair<int, int> > pq;
	vector<pair<int, int> >* edges = new vector<pair<int,int> >[V+1];
	for (int i = 0; i < E; ++i)
	{
		int sv, ev, w;
		cin >> sv >> ev >> w;
		edges[sv].push_back({ ev,w });
	}
	for (int i = 1; i <= V; ++i)
		table[i][1] = INF;
	table[S][1] = 0;
	pq.push({ -table[S][1], S });
	while (!pq.empty())
	{
		int min = -pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
	
		for (auto obj : edges[vertex])
			if (table[obj.first][1] > min + obj.second)
			{
				table[obj.first][0] = vertex;
				table[obj.first][1] = min + obj.second;
				pq.push({ -table[obj.first][1],obj.first });
			}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (table[i][1] == INF)cout << "INF" << endl;
		else cout << table[i][1] << endl;
	}
	delete[] edges;
	return 0;
}