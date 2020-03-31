#include <cstdio>
#include <queue>
#pragma warning(disable:4996)

using namespace std;

bool plane[10][10];
bool isCheck[10][10];

void bfs(int x, int y)
{
	if (plane[y][x])return;
	queue<pair<int, int>> que;
	plane[y][x] = true;
	isCheck[y][x] = true;
	que.push({ x,y });
	while (!que.empty())
	{
		pair<int, int> point = que.front();
		que.pop();
		int dx[4] = { -1,1,0,0 };
		int dy[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; ++i)
		{
			int X = point.first + dx[i];
			int Y = point.second + dy[i];
			if (Y < 0 || Y>9 || X < 0 || X>9)continue;
			if (isCheck[Y][X] == true)continue;
			isCheck[Y][X] = true;
			if (plane[Y][X] == true) continue;
			plane[Y][X] = true;
			que.push({ X,Y });
		}
	}
}
int main()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			char ch = getc(stdin);
			if (ch == '_') plane[y][x] = 0;
			else if (ch == '*')plane[y][x] = 1;
		}
		getchar();
	}
	int x, y;
	scanf("%d%d", &x, &y);
	bfs(x, y);
	

	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			if (plane[y][x] == false)
				printf("_");
			else
				printf("*");
		}
		printf("\n");
	}

	return 0;
}