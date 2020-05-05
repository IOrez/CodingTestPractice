#include <iostream>
#include <queue>
using namespace std;

int Table[1000][1000];
int	 Visited[1000][1000];

bool isInRange(int y, int x, int N,int M)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

int bfs(queue<pair<int, int> >& que, int N,int M)
{
	int result = 0;
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	while (!que.empty())
	{
		int posY = que.front().first;
		int posX = que.front().second;
		que.pop();
		if (Visited[posY][posX] > result)result = Visited[posY][posX];
		for (int i = 0; i < 4; ++i)
		{
			int dPosY = posY + dy[i];
			int dPosX = posX + dx[i];
			if (!isInRange(dPosY, dPosX, N, M))continue;
			if (Visited[dPosY][dPosX] == 0 && Table[dPosY][dPosX] == 0)
			{
				Visited[dPosY][dPosX] = Visited[posY][posX] + 1;
				que.push({ dPosY,dPosX });
			}
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	queue<pair<int, int>>que;
	int N, M;
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> Table[i][j];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Table[i][j] == 1)
				que.push({ i,j });

	int result =  bfs(que, N, M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (Table[i][j] == 0 && !Visited[i][j])
				result = -1;


	cout << result;

	return 0;
}