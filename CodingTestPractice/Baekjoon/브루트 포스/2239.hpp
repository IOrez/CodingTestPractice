#include <cstdio>
#include <cstdlib>
#pragma warning(disable:4996)

int Table[9][9];

void solution(int r, int c)
{
	if (r == 9 && c == 0)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
				printf("%d", Table[i][j]);
			printf("\n");
		}
		exit(0);
	}
	else if (Table[r][c] == 0)
	{
		int rPivot = r / 3 * 3, cPivot = c / 3 * 3;
		for (int num = 1; num <= 9; ++num)
		{
			bool check = false;
			for (int i = rPivot; i < rPivot + 3; ++i)
				for (int j = cPivot; j < cPivot + 3; ++j)
				{
					if (num == Table[i][j])check = true;
				}
			for (int i = 0; i < 9; ++i)
				if (num == Table[i][c])check = true;
			for (int i = 0; i < 9; ++i)
				if (num == Table[r][i])check = true;

			if (!check)
			{
				Table[r][c] = num;
				solution(r + (c + 1) / 9, (c + 1) % 9);
				Table[r][c] = 0;
			}
		}
	}
	else solution(r + (c + 1) / 9, (c + 1) % 9);
}

int main()
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			scanf("%1d", &Table[i][j]);

	solution(0,0);

	return 0;
}