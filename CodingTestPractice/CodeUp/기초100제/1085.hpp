#include <cstdio>
#pragma warning(disable:4996)


int main()
{
	long long int h, b, c, s;
	scanf("%lld %lld %lld %lld", &h, &b, &c, &s);

	printf("%.1lf MB", ((double)(h * b * c * s) / 8) / (1024 * 1024));

}