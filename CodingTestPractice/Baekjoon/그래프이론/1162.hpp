#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
int N, M, K;

using ll = long long;

priority_queue<pair<ll,pair<int, int>>> pq;
vector<pair<int, ll>> edge[10001];
vector<vector<ll>> cost(10001, vector<ll>(21, LLONG_MAX));
ll solution()
{
	pq.push({ 0,{1,0} });
	while (!pq.empty())
	{
		ll weight = -pq.top().first;
		int point = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();
		if (cost[point][cnt] < weight)continue;
		cost[point][cnt] = weight;
		for (size_t i = 0; i < edge[point].size(); ++i)
		{
			if (cost[edge[point][i].first][cnt] > weight + edge[point][i].second)
			{
				cost[edge[point][i].first][cnt] = weight + edge[point][i].second;
				pq.push({ -weight - edge[point][i].second, { edge[point][i].first,cnt } });
			}
			if (cnt < K && cost[edge[point][i].first][cnt + 1] > weight)
			{
				cost[edge[point][i].first][cnt + 1] = weight;
				pq.push({ -weight , { edge[point][i].first,cnt + 1 } });
			}
		}
	}
	ll Min = LLONG_MAX;
	for (int i = 0; i <= K; ++i)
		Min = min((ll)Min,cost[N][i]);
	return Min;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		ll start, end, weight;
		cin >> start >> end >> weight;
		edge[start].push_back({ end,weight });
		edge[end].push_back({ start,weight });
	}
	cout << solution();
	return 0;
}