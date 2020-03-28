#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int d = a / b;
		d += 1;
		int r = a % b;
		int val = b * d;
		if (r != 0)
			printf("%d\n", val - a);
		else
			printf("0\n");
	}
	return 0;
}