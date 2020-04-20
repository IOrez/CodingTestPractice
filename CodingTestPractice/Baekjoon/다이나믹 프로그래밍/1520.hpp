#include <iostream>

using namespace std;

int table[500][500];
int DP[500][500];
bool isCheck[500][500];

bool isInRange(int y, int x, int Y, int X)
{
	return 0 <= y && y < Y && 0 <= x && x < X;
}

int dfs(int y, int x,int Y,int X)
{
	if (y == Y - 1 && x == X-1)
		return 1;
	
	isCheck[y][x] = true;

	int dx[4]{ -1,1,0,0 };
	int dy[4]{ 0,0,1,-1 };

	for (int i = 0; i < 4; ++i)
	{
		int posX = x + dx[i];
		int posY = y + dy[i];
		if (isInRange(posY, posX, Y, X))
		{
			if (table[y][x] > table[posY][posX])
			{
				if (isCheck[posY][posX]) 
					DP[y][x] += DP[posY][posX];
				else
					DP[y][x] += dfs(posY, posX, Y, X);
			}
		}
	}
	return DP[y][x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int Y, X;
	cin >> Y >> X;
	for (int y = 0; y < Y; ++y)
		for (int x = 0; x < X; ++x)
			cin >> table[y][x];

	dfs(0, 0, Y, X);
	cout << DP[0][0];
	return 0;
}