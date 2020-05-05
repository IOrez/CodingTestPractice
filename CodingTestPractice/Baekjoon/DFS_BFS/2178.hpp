#include <cstdio>
#include <queue>

#pragma warning(disable:4996)

using namespace std;

int Visited[101][101];
int Table[101][101];

bool isInRange(int y, int x, int N, int M)
{
	return 1 <= y && y <= N && 1 <= x && x <= M;
}


int bfs(int y, int x, int N, int M)
{
	queue<pair<int, int> > que;
	que.push({ y,x });
	Visited[y][x] = 1;
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	while (!que.empty())
	{

		int posY = que.front().first;
		int posX = que.front().second;
		que.pop();
		if (posY == N && posX == M)return Visited[posY][posX];
		for (int i = 0; i < 4; ++i)
		{
			int dPosY = posY + dy[i];
			int dPosX = posX + dx[i];
			if (!isInRange(dPosY, dPosX, N, M))continue;
			if (Visited[dPosY][dPosX] != 0 || Table[dPosY][dPosX] == 0)continue;
			Visited[dPosY][dPosX] = Visited[posY][posX] + 1;
			que.push({ dPosY,dPosX });
		}
	}
	return -1;
}

int main()
{

	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%1d", &Table[i][j]);

	printf("%d", bfs(1, 1, N, M));



	return 0;
}