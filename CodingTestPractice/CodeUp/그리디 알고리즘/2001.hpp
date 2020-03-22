#include <cstdio>
#pragma warning(disable:4996)

int min(int a, int b)
{
	if (a > b)return b;
	else return a;
}

int main()
{
	int a, b, c, d, e;
	float min_pasta;
	float min_juice;

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	min_pasta = min(a, min(b, c));
	min_juice = min(d, e);

	printf("%.1f", (min_pasta + min_juice) * 1.1f);
	return 0;
}