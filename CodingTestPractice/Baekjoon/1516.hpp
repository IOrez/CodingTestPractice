#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int dp[501], edges[501];

#define MAX_BUILD_TIME  (100000*500);

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	vector<vector<int>> vTable[2];

	vTable[0].resize(N + 1);
	vTable[1].resize(N + 1);

	queue<int> que;
	for (int i = 1; i <= N; ++i)
	{
		cin >> dp[i];
		do
		{
			cin >> M;
			if (M == -1)
				break;
			vTable[0][i].push_back(M);
			vTable[1][M].push_back(i);
			edges[i]++;
		} while (true);
	}


	for (int i = 1; i <= N; ++i)
	{
		if (edges[i] != 0)
			continue;

		que.push(i);
	}

	while (!que.empty())
	{
		auto buildingNumber = que.front();
		que.pop();

		int minValue = MAX_BUILD_TIME;
		for (auto iter = vTable[0][buildingNumber].begin(); iter != vTable[0][buildingNumber].end(); iter++)
		{
			if (minValue > dp[*iter])
				minValue = dp[*iter];
		}
		dp[buildingNumber] += minValue;

		for (int i = 0; i < vTable[1][buildingNumber].size(); ++i)
		{
			int targetBuilding = vTable[1][buildingNumber][i];
			edges[targetBuilding]--;
			if (edges[targetBuilding] == 0)
				que.push(targetBuilding);
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << dp[i] << '\n';

}