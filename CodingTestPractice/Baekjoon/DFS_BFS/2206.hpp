#include <cstdio>
#include <tuple>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

#define INF 999999999

int Table[1001][1001];
int Visited[1001][1001][2];

bool isInRange(int y, int x, int N, int M)
{
	return 1 <= y && y <= N && 1 <= x && x <= M;
}

void bfs(int y, int x, int N, int M)
{
	queue<tuple<int, int, bool>>que;
	que.push({ y,x,false });
	Visited[y][x][0] = 1;
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	
	while (!que.empty())
	{
		auto [posY, posX, isCrashed] = que.front();
		que.pop();
		if (posY == N && posX == M)return;
		for (int i = 0; i < 4; ++i)
		{
			int dPosY = posY + dy[i];
			int dPosX = posX + dx[i];
			if (!isInRange(dPosY, dPosX, N, M))continue;
			
				if (Table[dPosY][dPosX] == 1 && !isCrashed)
				{
					if (Visited[dPosY][dPosX][1] == INF)
					{
						Visited[dPosY][dPosX][1] = Visited[posY][posX][0] + 1;
						que.push({ dPosY,dPosX,true });
					}
				}
				else if (Table[dPosY][dPosX] == 0)
				{
					if (Visited[dPosY][dPosX][isCrashed]==INF)
					{
						Visited[dPosY][dPosX][isCrashed] = Visited[posY][posX][isCrashed] + 1;
						que.push({ dPosY,dPosX,isCrashed });
					}
				}
			
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1;i<=N;++i)
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &Table[i][j]);
			Visited[i][j][0] = INF;
			Visited[i][j][1] = INF;
		}

	bfs(1, 1, N, M);
	int min = Visited[N][M][0] < Visited[N][M][1] ? Visited[N][M][0] : Visited[N][M][1];
	if (min == INF)printf("-1");
	else printf("%d", min);

	return 0;
}