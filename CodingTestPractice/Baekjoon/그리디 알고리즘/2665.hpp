
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

#pragma warning(disable:4996)
#define INT	9999999999

typedef struct Point
{
	int _col;
	int _row;

	bool operator == (Point& obj)
	{
		return this->_col == obj._col && this->_row == obj._row;
	}

}Point;

bool isInRange(int n, int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < n;
}


int bfs(int**& table, int**& DP, Point**& check, int n, int y, int x)
{
	queue<Point> que;
	que.push(Point{ y,x });
	DP[y][x] = 0;
	while (!que.empty())
	{
		Point pos = que.front();
		que.pop();
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,1,-1 };
		for (int i = 0; i < 4; ++i)
		{
			int Dx = pos._col + dx[i];
			int Dy = pos._row + dy[i];
			if (!isInRange(n, Dx, Dy))continue;
			if (table[Dy][Dx] == 1)
			{
				if (DP[Dy][Dx] > DP[pos._row][pos._col])
				{
					check[Dy][Dx] = pos;
					DP[Dy][Dx] = DP[pos._row][pos._col];
					que.push(Point{ Dx,Dy });
				}
			}
			else
			{
				if (DP[Dy][Dx] > DP[pos._row][pos._col] + 1)
				{
					check[Dy][Dx] = pos;
					DP[Dy][Dx] = DP[pos._row][pos._col] + 1;
					que.push(Point{ Dx,Dy });
				}
			}
		}
	}
	return DP[n - 1][n - 1];
}
int main()
{
	int n;
	scanf("%d", &n);
	int** table = new int* [n];
	int** DP = new int* [n];
	Point** check = new Point * [n];
	for (int i = 0; i < n; ++i) 
	{
		table[i] = new int[n];
		DP[i] = new int[n];
		check[i] = new Point[n];
	}
		
	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
		{
			scanf("%1d", &table[y][x]);
			DP[y][x] = INT;
			check[y][x] = Point{-1,-1};
		}


	printf("%d\n", bfs(table, DP, check, n, 0, 0));
	int y = n - 1;
	int x = n - 1;

	/*stack<Point>st;
	st.push(Point{ x,y });
	while (true)
	{
		Point pos = st.top();
		if (check[pos._row][pos._col] == Point{ -1,-1 })break;
		st.push(check[pos._row][pos._col]);
	}
	while (!st.empty())
	{
		printf("%d %d\n", st.top()._row+1, st.top()._col+1);
		st.pop();
	}*/
	for (int i = 0; i < n; ++i)
	{
		delete[] table[i];
		delete[] DP[i];
		delete[] check[i];
	}
	delete[] table;
	delete[] DP;
	delete[] check;
	return 0;
}