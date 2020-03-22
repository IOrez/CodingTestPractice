#include <cstdio>
#pragma warning (disable:4996)

int main()
{
	int n, m, a;
	unsigned long long result_w,result_h;
	scanf("%d %d %d", &n, &m, &a);

	result_w = (n / a) + ( n % a > 0 ? 1 : 0);
	result_h = (m / a) + ( m % a > 0 ? 1 : 0);

	printf("%lld", result_w * result_h);

	return 0;
}