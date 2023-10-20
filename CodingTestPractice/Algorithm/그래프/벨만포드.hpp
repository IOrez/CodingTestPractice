#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 9999999

int N, M;
vector<tuple<int, int, int>> edges;
int dist[1000000];

void Init()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int curnode, nextnode, cost;
		cin >> curnode >> nextnode >> cost;
		edges.push_back(make_tuple(curnode, nextnode, cost));
	}

	for (int i = 1; i <= N; i++)
		dist[i] = INF;
}

bool bellman_ford(int start)
{
	 dist[start] = 0;
	 for (int i = 1; i <= N; i++)
	 {
	 	 for (int j = 0; j < edges.size(); j++)
		 {
	 		int curnode = std::get<0>(edges[j]);
			int nextnode = std::get<1>(edges[j]);
			int cost = std::get<2>(edges[j]);

			if (dist[curnode] != INF && dist[nextnode] > dist[curnode] + cost)
			{
				dist[nextnode] = dist[curnode] + cost;
				if (i == N)
					return false;
			}
		 }
	 }
	 
	 return true;
}