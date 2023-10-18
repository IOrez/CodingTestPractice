#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, M, D;

int table[15][15];

int Simulate(int a, int b, int c)
{
	int tmpTable[15][15];
	int result = 0;
	memcpy(tmpTable, table, sizeof(int) * 15 * 15);

	queue<pair<int, int>> que;

	for (int t = 0; t < N; t++)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			if (i + t >= N || i + t < N - D)
				continue;

			for (int j = M-1; j >= 0; j--)
				if (tmpTable[i][j] == 1)
				{
					que.push(make_pair(i + t, j));
				}
		}

		pair<int, int> p[3] = {make_pair(0,M),make_pair(0,M),make_pair(0,M) };
		int minR[3] = { 99999,99999,99999 };
		while (!que.empty())
		{
			auto [y, x] = que.front();
			que.pop();

			int a_r = abs(a - x) + abs(N - y);
			int b_r = abs(b - x) + abs(N - y);
			int c_r = abs(c - x) + abs(N - y);

			if (a_r <= D && (a_r < minR[0] || a_r == minR[0] && p[0].second>x))
			{
				minR[0] = a_r;
				p[0] = make_pair(y - t, x);
			}

			if (b_r <= D && (b_r < minR[1] || b_r == minR[1] && p[1].second>x))
			{
				minR[1] = b_r;
				p[1] = make_pair(y - t, x);
			}

			if (c_r <= D && (c_r < minR[2] || c_r == minR[2] && p[2].second>x))
			{
				minR[2] = c_r;
				p[2] = make_pair(y - t, x);
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (minR[i] != 99999&& tmpTable[p[i].first][p[i].second] != 0)
			{
				tmpTable[p[i].first][p[i].second] = 0;
				result++;
			}
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> table[i][j];
		}
	}

	int ans = 0;
	for(int i = 0; i < M; i++)
		for(int j = i + 1; j < M ; j++)
			for (int k = j + 1; k < M; k++)
			{
				ans = max(ans, Simulate(i, j, k));
			}

	cout << ans;

	return 0;
}