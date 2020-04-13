#include <iostream>
#include <stack>
using namespace std;

char table[10000][500];
bool check[10000][500];
int cnt = 0;

void dfs(int R,int C,int posX,int posY)
{
	stack<pair<int, int>> st;
	int dx[3] = { 1,1,1 };
	int dy[3] = { -1,0,1 };
	st.push({ posX,posY });
	while (!st.empty())
	{
		int x = st.top().first;
		int y = st.top().second;
		st.pop();
		for (int i = 0; i < 3; ++i)
		{
			check[y][x] = true;
			if (x == C) { cnt++; return; }
			int px = x + dx[i];
			int py = y + dy[i];
			if (py < 0 || py >= R)continue;
			if (check[py][px] == false&&table[py][px] != 'x')
			{
				st.push({ x,y });
				x = px;
				y = py;
				i = -1;
			}
		}
	}
}

int main()
{
	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		cin >> table[i];

	for (int i = 0; i < R; ++i)
		dfs(R,C - 1, 0, i);

	cout << cnt;
	return 0;
}