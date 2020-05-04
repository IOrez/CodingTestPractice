#include <iostream>
#include <queue>

using namespace std;

bool MineMap[10][10];
char Map[10][10];


bool isInRange(int y, int x)
{
	return 1 <= y && y < 10 && 1 <= x && x < 10;
}

void bfs(int y, int x)
{
	queue<pair<int, int> >que;
	que.push({ y,x });
	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		if (MineMap[y][x] == 1) { Map[y][x] = '.'; break; };
		int dy[8] = { 1,-1,1,-1,0,0,1,-1 };
		int dx[8] = { 1,1,-1,-1,1,-1,0,0 };
		int count = 0;
		vector<pair<int, int> > v;
		for (int i = 0; i < 8; ++i)
		{
			int posy = y + dy[i];
			int posx = x + dx[i];
			if (MineMap[posy][posx] == 1)count++;
			else if (Map[posy][posx] == '_')
				v.push_back({ posy,posx });
		}
		if(count==0)
			for (auto i : v)que.push(i);
		Map[y][x] = '0' + count;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
		{
			cin >> MineMap[i][j];
			Map[i][j] = '_';
		}

	int y, x;
	cin >> y >> x;
	bfs(y, x);

	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			if (Map[i][j] == '.')cout << "-1 ";
			else cout<< Map[i][j]<<" ";
		}
		cout << "\n";
	}


	return 0;
}