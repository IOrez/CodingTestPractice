#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[25][25];
bool table[25][25];

#pragma warning(disable:4996)

bool isInRange(int n, int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < n;
}

void bfs(int y, int x, int n, int& cnt)
{
	visited[y][x] = true;
	queue<pair<int, int>> que;
	que.push({y,x});
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int dPosY = y + dy[i];
			int dPosX = x + dx[i];
			if (!isInRange(n, dPosY, dPosX))continue;
			if (table[dPosY][dPosX] == 0 || visited[dPosY][dPosX])continue;
			visited[dPosY][dPosX] = true;
			cnt++;
			que.push({ dPosY,dPosX });
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%1d", &table[i][j]);
	
	vector<int>v;
	for(int i = 0;i<N;++i)
		for (int j = 0; j < N; ++j)
			if (table[i][j] == 1 && visited[i][j] == false)
			{
				int cnt = 1;
				bfs(i, j, N, cnt);
				v.push_back(cnt);
			}

	sort(v.begin(), v.end());
	printf("%d\n", v.size());
	for (auto i : v)
		printf("%d\n", i); 

	return 0;
}