#include <cstdio>
#pragma warning(disable:4996)

bool arr[20][20];

void switching(int x, int y)
{
	for (int i = 0; i < 20; ++i)
		arr[x][i] = !arr[x][i];
	for (int i = 0; i < 20; ++i)
		arr[i][y] = !arr[i][y];
}

int main()
{
	for (int i = 1; i < 20; ++i)
	{
		for (int j = 1; j < 20; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		switching(x, y);
	}

	for (int i = 1; i < 20; ++i)
	{
		for (int j = 1; j < 20; ++j)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}