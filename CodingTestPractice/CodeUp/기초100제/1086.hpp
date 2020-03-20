#include <cstdio>
#pragma warning(disable:4996)


int main()
{
	long long w, h, b;
	scanf("%lld %lld %lld", &w, &h, &b);

	printf("%.2lf MB", (double)(w * h * b / 8) / (1024 * 1024));

}