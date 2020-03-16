#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	long long int a, b,c;
	scanf("%lld %lld %lld",&a,&b,&c);
	printf("%lld\n%.1lf", (a + b + c),(double)(a + b + c) / 3);

	return 0;
}