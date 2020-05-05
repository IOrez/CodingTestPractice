#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool Visited[100][100];
int Table[100][100];

bool isInRange(int y, int x, int N)
{
	return 0 <= y && y < N && 0 <= x && x < N;
}

void bfs(int y, int x, int N,int number)
{
	Visited[y][x] = true;
	queue<pair<int, int> > que;
	que.push({ y,x });
	int dy[4] = { 1,-1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	while (!que.empty())
	{
		int posY = que.front().first;
		int posX = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int dPosY = posY + dy[i];
			int dPosX = posX + dx[i];
			if (!isInRange(dPosY, dPosX, N))continue;
			if (Table[dPosY][dPosX] <= number || Visited[dPosY][dPosX])continue;
			Visited[dPosY][dPosX] = true;
			que.push({ dPosY,dPosX });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> Table[i][j];
	
	int max_c = -1;
	for (int k = 0; k <= 100; ++k)
	{
		int cnt = 0;
		memset(Visited, false, sizeof(Visited));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (Table[i][j] > k && !Visited[i][j])
				{
					cnt++;
					bfs(i, j, N, k);
				}
		if (max_c < cnt)max_c = cnt;
	}
	
	cout << max_c;
	
	
	return 0;
}
