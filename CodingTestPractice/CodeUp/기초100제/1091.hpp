#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)


int main()
{
	long long a, m, d,n;
	scanf("%lld %lld %lld %lld", &a, &m, &d,&n);

	long long t = a;
	for (int i = 1; i < n; ++i)
		t = t * m + d;
	
	printf("%lld", t);
	return 0;
}