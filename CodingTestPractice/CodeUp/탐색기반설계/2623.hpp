#include <cstdio>
#pragma warning(disable:4996)

void swab(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
int gcd(int a, int b)
{
	if (a < b)swab(a, b);
	if (b == 0)return a;
	else return gcd(b, a % b);
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", gcd(a, b));
	return 0;
}