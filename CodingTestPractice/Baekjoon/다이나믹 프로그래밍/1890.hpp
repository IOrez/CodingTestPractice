#include <iostream>

using namespace std;

using ull = unsigned long long;

ull DP[100][100];
int Table[100][100];

bool isInRange(int n, int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < n;
}

ull dfs(int n,int y,int x)
{	
	if (y == n - 1 && x == n - 1)return 1;
	if (!isInRange(n, y, x))return 0;
	if (DP[y][x] != 0)return DP[y][x];
	if (Table[y][x] == 0)return DP[y][x];
	int dy[2] = { Table[y][x] ,0 };
	int dx[2] = { 0,Table[y][x] };
	for (int i = 0; i < 2; ++i)
	{
		int posY = y + dy[i];
		int posX = x + dx[i];
		DP[y][x] += dfs(n, posY, posX);
	}
	return DP[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	for (int y = 0; y < n; ++y)
		for (int x = 0; x < n; ++x)
			cin >> Table[y][x];


	cout << dfs(n, 0, 0);


	return 0;
}