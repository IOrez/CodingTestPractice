#include <iostream>

using namespace std;

int Table[1000][1000];
bool check[1000][1000];
enum class Type
{
	OO,EO,OE,EE
};


void func_OO_OE(int N,int M)
{
	bool toRight = true;
	int col = 0;
	for (int i = 0; i < N;)
	{
		if (i == N - 1 && col == M - 1)break;
		if (toRight)
		{
			if (col + 1 == M)
			{
				cout << "D";
				i++;
				toRight = false;
			}
			else
			{
				cout << "R";
				col++;
			}
		}
		else
		{
			if (col - 1 == -1)
			{
				cout << "D";
				i++;
				toRight = true;
			}
			else
			{
				cout << "L";
				col--;
			}
		}
	}
};

void func_EO(int N, int M)
{
	bool toDown = true;
	int row = 0;
	for (int i = 0; i < M;)
	{
		if (row == N - 1 && i == M - 1)break;
		if (toDown)
		{
			if (row + 1 == N)
			{
				cout << "R";
				i++;
				toDown = false;
			}
			else
			{
				cout << "D";
				row++;
			}
		}
		else
		{
			if (row - 1 == -1)
			{
				cout << "R";
				i++;
				toDown = true;
			}
			else
			{
				cout << "UP";
				row--;
			}
		}
	}
}

void func_EE(int N, int M,int MinposX,int MinposY)
{
	int dx[4] = { 0,1,-1,0 };
	int dy[4] = { -1,0,0,1 };
	auto isInRange = [&](int N, int M, int y, int x)
	{
		return 0 <= y && y < N && 0 <= x && x < M;
	};
	int posY = 0,posX = 0;
	check[posY][posX] = true;
	bool isLeft = true;
	for (int i = 0; i < 4; ++i)
	{
		if (posY == N - 1 && posX == M - 1)
		{
			break;
		}
		int dPosX = posX + dx[i];
		int dPosY = posY + dy[i];
		if (isInRange(N, M, dPosY, dPosX))
		{
			if (dPosX == MinposX && dPosY == MinposY)continue;
			if (check[dPosY][dPosX])continue;
			check[dPosY][dPosX] = true;
			switch (i)
			{
			case 0:
				cout << "U";
				i = -1;
				break;
			case 1:
			case 2:
				if (dx[i] == 1)
				{
					cout << "R";
					dx[1] = 1;
					dx[2] = -1;
					i = -1;
					break;
				}
				else if (dx[i] == -1)
				{
					cout << "L";
					dx[1] = -1;
					dx[2] = 1;
					i = -1;
					break;
				}
			case 3:
				cout << "D";
				if (dPosX == 0)
				{
					dx[1] = 1;
					dx[2] = -1;
				}
				else if (dPosX == M - 1)
				{
					dx[1] = -1;
					dx[2] = 1;
				}
				i = -1;
				break;
			}
			posY = dPosY;
			posX = dPosX;
		}
	}
	int a = 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	Type type;
	cin >> N >> M;
	
	

	int min = 9999999;
	int min_row = -1;
	int min_col = -1;


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			cin >> Table[i][j];
			if ((i + j) % 2 && min > Table[i][j]&&!(i==N-1&&j==M-1))
			{
				min = Table[i][j];
				min_row = i;
				min_col = j;
			}

		}
	if (N % 2 == 0 && M % 2 == 0)type = Type::EE;
	else if (N % 2 == 1 && M % 2 == 0)type = Type::OE;
	else if (N % 2 == 0 && M % 2 == 1)type = Type::EO;
	else if (N % 2 == 1 && M % 2 == 1)type = Type::OO;
	switch (type)
	{
	case Type::OO:
	case Type::OE:
		func_OO_OE(N, M);
		break;
	case Type::EO:
		func_EO(N, M);
		break;
	case Type::EE:
		func_EE(N, M, min_col,min_row);
		break;
	}
	
	return 0;
}