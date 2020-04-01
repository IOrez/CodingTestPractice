#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

int arr[1002];
int DP[1002];

void init(const int N)
{
	DP[N] = 1;
	for (int i = N; i > 0; --i)
	{
		for (int j = i - 1; j < N; ++j)
		{
			if (arr[i - 1] >= arr[j + 1])continue;
			DP[i - 1] = DP[i - 1] > DP[j + 1] ? DP[i - 1] : DP[j + 1];
		}
		DP[i - 1] += 1;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);

	init(N);
	int max = -1;
	for (int i = 1; i <= N; ++i)
		if (max < DP[i])max = DP[i];
	printf("%d", max);
	return 0;
}