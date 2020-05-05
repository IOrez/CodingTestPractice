#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool Table[100][100];
bool Visited[100][100];

bool isInRange(int y, int x, int N, int M)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(int y, int x, int N, int M,int& cnt)
{
	Visited[y][x] = true;
	queue<pair<int, int> >que;
	cnt++;
	que.push({ y,x });
	int dy[4] = { 0,0,1,-1 };
	int dx[4] = { 1,-1,0,0 };
	while (!que.empty())
	{
		int posY = que.front().first;
		int posX = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i) 
		{
			int dPosY = posY + dy[i];
			int dPosX = posX + dx[i];
			if (!isInRange(dPosY, dPosX, N, M))continue;
			if (Table[dPosY][dPosX] == 1 || Visited[dPosY][dPosX])continue;
			cnt++;
			Visited[dPosY][dPosX] = true;
			que.push({ dPosY,dPosX });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int left, top, right, bottom;
		cin >> left >> bottom >> right >> top;
		for (int j = left; j < right; ++j)
			for (int k = N - top; k < N - bottom; ++k)
				Table[k][j] = 1;
	}
	
	vector<int> v;
	for(int i = 0;i<N;++i)
		for (int j = 0; j < M; ++j)
			if (Table[i][j] == 0 && Visited[i][j] == false)
			{
				int cnt = 0;
				bfs(i, j, N, M, cnt);
				v.push_back(cnt);
			}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto i : v)cout << i << " ";
	return 0;
}