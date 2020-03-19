#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n;
	scanf("%d", &n);
	while ((bool)n)
	{
		printf("%d\n", n--);
	}

	return 0;
}