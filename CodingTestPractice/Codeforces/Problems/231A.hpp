#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n;
	scanf("%d", &n);
	int result = 0;
	for (int i = 1; i <=n; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int sum = a + b + c;
		result += (sum >= 2 ? 1 : 0);
	}
	printf("%d", result);
	return 0;
}