#include <cstdio>

#pragma warning(disable:4996)

int table[2][50][50];
int cnt = 0;
void change(const int posY, const int posX)
{
	int dx[9] = { -1,-1,-1,0,0,0,1,1,1 };
	int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
	for (int i = 0; i < 9; ++i)
	{
		int changePosX = posX + dx[i];
		int changePosY = posY + dy[i];
		table[0][changePosY][changePosX] = !table[0][changePosY][changePosX];
	}
	cnt++;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &table[0][i][j]);


	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			scanf("%1d", &table[1][i][j]);


	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j < M - 1; ++j)
		{
			if (table[0][i-1][j-1] != table[1][i-1][j-1]) 
				change(i, j);
		}
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			if (table[0][i][j] != table[1][i][j])
				cnt = -1;
				
			
		
		
	
	printf("%d", cnt);
	return 0;
}