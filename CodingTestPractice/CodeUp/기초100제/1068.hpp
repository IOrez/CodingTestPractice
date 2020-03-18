#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n;
	scanf("%d", &n);
	if (n >= 90)printf("A\n");
	else if (n >= 70)printf("B\n");
	else if (n >= 40)printf("C\n");
	else if (n >= 0)printf("D\n");
	return 0;
}