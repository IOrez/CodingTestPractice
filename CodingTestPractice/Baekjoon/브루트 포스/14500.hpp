#include <iostream>
#include <vector>
using namespace std;
int Table[500][500];
int Max = 0;

bool isInRange(int y, int x, int n, int m)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}

typedef struct point
{
	int posY, posX;
}point;

typedef struct tetromino
{
	point block[4];
}tetromino;


tetromino blocks[5][8]
= {
	{tetromino{0,0,0,1,-1,0,-2,0},tetromino{0,0,-1,0,-1,1,-1,2},tetromino{0,0,-1,0,-2,0,-2,-1},tetromino{0,0,0,1,0,2,-1,2},
	 tetromino{0,0,0,1,-1,1,-2,1},tetromino{0,0,-1,0,0,1,0,2},tetromino{0,0,-1,0,-2,0,-2,1},tetromino{0,0,-1,0,-1,-1,-1,-2}},//type 1
	{tetromino{0,0,-1,0,-1,-1,-2,-1},tetromino{0,0,0,1,-1,1,-1,2},tetromino{0,0,-1,0,-1,-1,-2,-1},tetromino{0,0,0,1,-1,1,-1,2},
	 tetromino{0,0,-1,0,-1,1,-2,1},tetromino{0,0,0,1,-1,0,-1,-1},tetromino{0,0,-1,0,-1,1,-2,1},tetromino{0,0,0,1,-1,0,-1,-1}},//type 2
	{tetromino{0,0,-1,0,-1,-1,-1,1},tetromino{0,0,-1,0,-1,-1,-2,0},tetromino{0,0,0,1,0,2,-1,1},tetromino{0,0,-1,0,-2,0,-1,1},
	 tetromino{0,0,-1,0,-1,-1,-1,1},tetromino{0,0,-1,0,-1,-1,-2,0},tetromino{0,0,0,1,0,2,-1,1},tetromino{0,0,-1,0,-2,0,-1,1}},//type 3
	{tetromino{0,0,0,1,0,2,0,3},tetromino{0,0,-1,0,-2,0,-3,0},tetromino{0,0,0,1,0,2,0,3},tetromino{0,0,-1,0,-2,0,-3,0},
	 tetromino{0,0,0,1,0,2,0,3},tetromino{0,0,-1,0,-2,0,-3,0},tetromino{0,0,0,1,0,2,0,3},tetromino{0,0,-1,0,-2,0,-3,0}},//type 4
	{tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1},
	 tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1},tetromino{0,0,0,1,-1,0,-1,1}},//type 5
};

void solution(int y, int x,int n,int m)
{
	if (y != 0 || x != m - 1) {
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 8; ++j)
			{
				int sum = 0;
				bool inRange = true;
				for (int k = 0; k < 4; ++k)
				{
					inRange = isInRange(y + blocks[i][j].block[k].posY, x + blocks[i][j].block[k].posX, n, m);
					if (!inRange)break;
				}
				if (!inRange)continue;
				for (int k = 0; k < 4; ++k)
					sum += Table[y + blocks[i][j].block[k].posY][x + blocks[i][j].block[k].posX];
				if (Max < sum)Max = sum;
			}
		solution(y - (x + 1) / m, (x + 1) % m, n, m);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> Table[i][j];

	solution(N-1, 0, N, M);
	cout << Max;

	return 0;
}