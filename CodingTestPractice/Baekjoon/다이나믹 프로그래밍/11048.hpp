#include <iostream>
#include <queue>
using namespace std;

int DP[1001][1001];
int table[1001][1001];
int N, M;

bool isInRange(int y, int x)
{
	return 1 <= y && y <= N && 1 <= x && x <= M;
}

void solution(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({ y,x });
	DP[y][x] = table[y][x];
	int dy[3] = { 0,1,1 };
	int dx[3] = { 1, 0, 1 };
	while (!que.empty())
	{
		int posY = que.front().first;
		int posX = que.front().second;
		que.pop();
		for (int i = 0; i < 3; ++i)
		{
			int yy = dy[i] + posY;
			int xx = dx[i] + posX;
			if (!isInRange(yy, xx))continue;
			if (DP[posY][posX] + table[yy][xx] <= DP[yy][xx])continue;
			DP[yy][xx] = DP[posY][posX] + table[yy][xx];
			que.push({ yy,xx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> table[i][j];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if(DP[i][j]==0)
				solution(i, j);

	cout << DP[N][M];
	return 0;
}