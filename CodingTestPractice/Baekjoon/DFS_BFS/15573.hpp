#include <iostream>
#include <queue>
using namespace std;


int table[1000][1000];
int N, M, K;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
bool check[1000][1000];
priority_queue<pair<int,pair<int, int>>> que;

bool isInRange(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

int solution()
{
	int max = -1;
	while (K--)
	{
		int d = -que.top().first;
		auto pos = que.top().second;
		que.pop();
		if (max < d)
			max = d;

		for (int i = 0; i < 4; ++i)
		{
			int posY = dy[i] + pos.first;
			int posX = dx[i] + pos.second;
			if (!isInRange(posY, posX))continue;
			if (check[posY][posX])continue;
			que.push({ -table[posY][posX],{posY,posX} });
			check[posY][posX] = true;
		}
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> table[i][j];

	for (int i = 0; i < M; ++i)
	{
		que.push({ -table[0][i],{0,i} });
		check[0][i] = true;
	}
	for (int i = 1; i < N; ++i)
	{
		que.push({ -table[i][0],{i,0} });
		que.push({ -table[i][M - 1],{i,M - 1} });
		check[i][0] = true;
		check[i][M - 1] = true;
	}

	cout << solution();

	return 0;
}