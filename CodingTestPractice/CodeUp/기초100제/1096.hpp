#include <cstdio>
#pragma warning(disable:4996)

bool arr[20][20];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = true;
	}

	for (int y = 1; y < 20; ++y)
	{
		for (int x = 1; x < 20; ++x)
			printf("%d ", arr[y][x]);
		printf("\n");
	}
	return 0;
}