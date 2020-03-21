#include <cstdio>
#pragma warning(disable:4996)

int miro[11][11];

void findPath()
{
	int Ax = 2,Ay = 2;
	while (true)
	{
		if (miro[Ax][Ay] == 2) { miro[Ax][Ay] = 9; break; }
		miro[Ax][Ay] = 9;
		if (miro[Ax][Ay + 1] == 1) {
			if (miro[Ax + 1][Ay] == 1)break;
			Ax += 1;
		}
		else Ay += 1;
	}

	for (int x = 1; x < 11; ++x)
	{
		for (int y = 1; y < 11; ++y)
			printf("%d ", miro[x][y]);
		printf("\n");
	}

	return;
}

int main()
{
	for (int x = 1; x < 11; ++x)
		for (int y = 1; y < 11; ++y)
			scanf("%d", &miro[x][y]);
	
	findPath();

	return 0;
}