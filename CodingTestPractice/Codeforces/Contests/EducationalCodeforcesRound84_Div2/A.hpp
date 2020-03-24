#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int testCase;
	scanf("%d", &testCase);
	for (int test = 0; test < testCase; ++test)
	{
		long long n, k;
		scanf("%lld%lld", &n, &k);
		if ((n <(k * k)) || ((n - k) & 0x1))printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}