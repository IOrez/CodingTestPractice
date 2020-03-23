#include <cstdio>
#pragma warning(disable:4996)

#define MODVAL 1000000000

unsigned long long arr[101][10];

void init()
{
	for (int i = 0; i < 10; ++i)
		arr[1][i] = 1;
}

int main()
{
	int N;
	init();
	scanf("%d", &N);
	for (int i = 2; i <= N; ++i)
	{
		arr[i][0] = arr[i - 1][1];
		for(int j = 1;j<9;++j)
			arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1])%MODVAL;
		arr[i][9] = arr[i - 1][8];
	}
	unsigned long long sum = 0;
	for (int i = 0; i < 9;++i)
		sum = (sum + arr[N][i]) % MODVAL;
	printf("%llu", sum);
	return 0;
}