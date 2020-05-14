#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 99999999

bool check[10001];
vector<pair<short, short>> v[10001];
int Table[10001][2];

int main()
{
	int testCase = 0;
	cin >> testCase;
	while (testCase--)
	{
		memset(check, false, sizeof(check));
		int N,D,C;
		int cnt = 0, sum = 0;
		cin >> N >> D >> C;
		for (int i = 0; i < D; ++i)
		{
			int startV,endV;
			short weight;
			cin >> endV >> startV >> weight;
			v[startV].push_back({weight,endV});
		}
		for (int i = 1; i <= N; ++i)
		{
			Table[i][0] = C;
			Table[i][1] = INF;
		}
		check[C] = true;
		Table[C][1] = 0;
		cnt++;
		for (auto info : v[C])
		{
			for (int i = 1; i <= N; ++i)
				Table[info.second][1] = info.first;
		}
		while (true)
		{
			int min = INF;
			int vertex = -1;
			for (int i = 1; i <= N; ++i)
				if (!check[i] && min > Table[i][1])
				{
					vertex = i;
					min = Table[i][1];
				}
			if (min == INF)break;
			if (min > 0)sum += min;
			cnt++; check[vertex] = true;
			for (int i = 1; i <= N; ++i)
				if (!check[i] && Table[i][1] != INF)
					Table[i][1] -= min;

			for (auto info : v[vertex])
			{
				for (int i = 1; i <= N; ++i)
					if (!check[i])
					{
						if (Table[info.second][1] > info.first)
						{
							Table[info.second][0] = vertex;
							Table[info.second][1] = info.first;
						}

					}
			}
		}
		for (int i = 1; i <= N; ++i) v[i].clear();
		cout << cnt << " " << sum << endl;
	}
	return 0;
}