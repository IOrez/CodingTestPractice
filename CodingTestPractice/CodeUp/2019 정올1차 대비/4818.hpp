#include <iostream>


using namespace std;

int DP[15][15];
bool check[15][15];

typedef struct point 
{
	int _x;
	int _y;
}Point;

bool operator ==(const Point& obj1, const Point& obj2)
{
	return obj1._x == obj2._x && obj1._y == obj2._y;
}

bool isInRange(const Point& pos,const Point LT,const Point RB)
{
	return LT._y <= pos._y && pos._y <= RB._y && LT._x <= pos._x && pos._x <= RB._x;
}

int  dfs(Point pos, const Point LT, const Point RB)
{
	if (pos == RB)
		return 1;
	check[pos._y][pos._x] = true;
	int dx[2] = { 0,1 };
	int dy[2] = { 1,0 };

	for (int i = 0; i < 2; ++i)
	{
		Point dir_pos = { pos._x + dx[i],pos._y + dy[i] };
		if (!isInRange(dir_pos, LT, RB))continue;
		if (check[dir_pos._y][dir_pos._x])DP[pos._y][pos._x] += DP[dir_pos._y][dir_pos._x];
		else
			DP[pos._y][pos._x] += dfs(dir_pos, LT, RB);
	}
	return DP[pos._y][pos._x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	K -= 1;
	int cnt = 0;
	if (K == -1)
		cnt = dfs(Point{ 0,0 }, Point{ 0,0 }, Point{ N-1,M-1 });
	else
	{
		cnt = dfs(Point{ 0,0 }, Point{ 0,0 }, Point{ (K / M),K % M });
		cnt *= dfs(Point{ (K / M),K % M }, Point{ (K / M),K % M }, Point{ N-1,M-1 });
	}
	cout << cnt;
	return 0;
}