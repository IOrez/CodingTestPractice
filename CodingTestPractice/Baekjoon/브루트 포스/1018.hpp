#include <cstdio>
#pragma warning(disable:4996)
bool Table[50][50];

unsigned int Min = -1;

void solution(int r, int c)
{
	for (int t = 0; t < 2; ++t)
	{
		bool color = t;
		for (int si = 0; si <= r - 8; ++si)
			for (int sj = 0; sj <= c - 8; ++sj)
			{
				int sum = 0;
				for (int i = si; i < si + 8; ++i)
					for (int j = sj; j < sj + 8; ++j)
					{
						if (color != Table[i][j])sum++;
						if (j != sj + 7)
							color = !color;
					}
				if (Min > sum)Min = sum;
			}
	}
}

int main()
{
	int r, c;
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			char ch;
			scanf("%c", &ch);
			if (ch == 'W')Table[i][j] = 1;
			else Table[i][j] = 0;
		}
		getchar();
	}
	solution(r, c);
	printf("%d", Min);

	return 0;
}