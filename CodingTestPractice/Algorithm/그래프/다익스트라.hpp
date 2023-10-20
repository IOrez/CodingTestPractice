#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  Dis[1001];
bool check[1001];
vector<vector<int>> table(1001);
int A, B, N, M;

int dijkstra()
{
	while (true)
	{
		int Min = 1 << 31 - 1, Idx = -1;
		for (int i = 1; i <= N; ++i)
			if (Min > Dis[i] && !check[i])
			{
				Idx = i;
				Min = Dis[i];
			}
		if (Idx == B)break;
		else if (Idx == -1)break;

		check[Idx] = true;
		for (auto& i : table[Idx])
			if (!check[i])Dis[i] = min({ Dis[i],Dis[Idx] + 1 });
	}

	if (Dis[B] == 1 << 31 - 1)Dis[B] = -1;
	return Dis[B];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)Dis[i] = 1 << 31 - 1;
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		table[s].push_back(e);
		table[e].push_back(s);
	}

	for (auto& i : table[A])
		Dis[i] = 1;

	Dis[A] = 0;
	check[A] = true;

	cout << dijkstra();
	return 0;
}