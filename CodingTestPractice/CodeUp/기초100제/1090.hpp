#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)


int main()
{
	long long a, r, n;
	scanf("%lld %lld %lld", &a, &r, &n);

	printf("%lld", a *(int)pow(r,n-1));
	return 0;
}