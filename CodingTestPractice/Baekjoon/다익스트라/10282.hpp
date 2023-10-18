#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int T, N, D, C;

vector<pair<int,int>> vTable[10001];
bool check[10001];

void Solution()
{
	int tot = 0, tot_time = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, C));

	while (!pq.empty())
	{
		auto [t, node] = pq.top();
		pq.pop();

		if (check[node] == true)
			continue;

		tot++;
		check[node] = true;

		t *= -1;
		tot_time = max(tot_time, t);

		for (int i = 0; i < vTable[node].size(); i++)
		{
			int nextNode = vTable[node][i].first;
			if (check[nextNode] == true)
				continue;
			pq.push(make_pair(-(t + vTable[node][i].second), nextNode));
		}
	}

	cout << tot << " " << tot_time << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	while (T--)
	{
		cin >> N >> D >> C;
		for (int i = 1; i <= N; i++)
		{
			vTable[i].clear();
			check[i] = false;
		}

		int a, b, s;
		for (int i = 0; i < D; i++)
		{
			cin >> a >> b >> s;
			vTable[b].push_back(make_pair(a, s));
		}

		Solution();
	}
	return 0;
}