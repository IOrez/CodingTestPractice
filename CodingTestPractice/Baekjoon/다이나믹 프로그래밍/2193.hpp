#include <cstdio>
#pragma warning(disable:4996)

unsigned long long DP[91];

void init()
{
	DP[1] = 1;		//1
	DP[2] = 1;		//10
	for (int i = 3; i <= 90; ++i)
		DP[i] = DP[i - 1] + DP[i - 2];
}

int main()
{
	init();
	int n;
	scanf("%d", &n);
	printf("%llu", DP[n]);
	return 0;
}