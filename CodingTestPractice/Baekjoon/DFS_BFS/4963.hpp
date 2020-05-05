#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool table[50][50];
bool visited[50][50];

bool isInRange(int n,int m, int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y,int x, int n,int m)
{
	visited[y][x] = true;
	int dy[8] = { 0,0,1,-1,1,1 ,-1,-1};
	int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
	for (int i = 0; i < 8; ++i)
	{
		int posY = y + dy[i];
		int posX = x + dx[i];
		if (!isInRange(n,m, posY, posX))continue;
		if (table[posY][posX] == 0 || visited[posY][posX])continue;
		dfs(posY, posX, n,m);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (true)
	{
		int N, M;
		cin >> M >> N;
		if (N == 0 && M == 0)break;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				cin >> table[i][j];

		int cnt = 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (!visited[i][j] && table[i][j] == 1)
				{
					cnt++;
					dfs(i, j, N,M);
				}

		cout << cnt << endl;
	}
	return 0;
}