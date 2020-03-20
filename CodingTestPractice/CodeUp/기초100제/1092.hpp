#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int day = 1;
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for (day = 1; day % a != 0 || day % b != 0 || day % c != 0; ++day) {}
	printf("%d", day);
	return 0;
}