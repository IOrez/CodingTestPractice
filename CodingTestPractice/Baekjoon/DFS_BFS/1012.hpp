#include <iostream>
#include <queue>
#include <cstring>

bool check[50][50];
bool table[50][50];
int testCase,N,M,K,y,x,cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
using namespace std;

bool isInRange(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

void bfs(int y, int x)
{
	queue<pair<int, int> > que;
	check[y][x] = true;
	que.push({ y,x });
	while (!que.empty())
	{
		auto posY = que.front().first;
		auto posX = que.front().second;
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int yy = posY + dy[i];
			int xx = posX + dx[i];
			if (!isInRange(yy, xx))continue;
			if (table[yy][xx] && !check[yy][xx])
			{
				check[yy][xx] = true;
				que.push({ yy,xx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> testCase;
	while (testCase--)
	{
		memset(table, 0, sizeof(table));
		memset(check, 0, sizeof(check));
		cin >> M >> N >> K;
		for (int i = 0; i < K; ++i)
		{
			cin >> x >> y;
			table[y][x] = true;
		}
		cnt = 0;
		for(int i=0;i<N;++i)
			for (int j = 0; j < M; ++j)
				if (!check[i][j] && table[i][j])
				{
					cnt++;
					bfs(i, j);
				}
		cout << cnt << '\n';
	}
	return 0;
}

