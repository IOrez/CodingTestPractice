#include <cstdio>
#pragma warning(disable:4996)

char arr[101][101];

int main()
{
	int w, h;
	int n;
	int l, d, x, y;

	scanf("%d %d %d", &h, &w,&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d %d", &l, &d, &x, &y); 
		if (d == 0)
		{
			for (int i = 0; i < l; ++i)
				arr[x][y+i] = true;
		}
		else
		{
			for (int i = 0; i < l; ++i)
				arr[x+i][y] = true;
		}
	}
	
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 1; j <= w; ++j)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	return 0;
}