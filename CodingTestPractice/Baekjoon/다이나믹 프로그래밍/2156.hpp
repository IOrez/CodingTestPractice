#include <cstdio>
#pragma warning(disable:4996)

#define MAX_BUF_SIZE	10001

int arr[MAX_BUF_SIZE];
int DP[MAX_BUF_SIZE];
int init()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);


	DP[1] = arr[1];
	DP[2] = arr[2] + arr[1];
	int val = (arr[3] + (arr[1] > arr[2] ? arr[1] : arr[2]));
	DP[3] = val > DP[2] ? val : DP[2];
	for (int i = 4; i <= n; ++i)
	{
		int val_a = arr[i] + arr[i-1] + DP[i-3];
		if (val_a < DP[i - 1]) val_a = DP[i - 1];
		int val_b = arr[i] + DP[i-2];
		if (val_b < DP[i - 1])val_b = DP[i - 1];
		DP[i] = val_a > val_b ? val_a : val_b;
	}
	return n;
}

int main()
{
	int n = init();
	int max = DP[0];
	for (int i = 1; i <= n; ++i)
		if (max < DP[i])max = DP[i];

	printf("%d", max);
	return 0;
}