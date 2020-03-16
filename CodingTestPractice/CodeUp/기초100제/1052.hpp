#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a != b ? 1 : 0);
	return 0;
}