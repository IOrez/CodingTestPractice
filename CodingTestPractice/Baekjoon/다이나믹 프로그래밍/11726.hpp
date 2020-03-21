#include <cstdio>
#pragma warning(disable:4996)


int arr[1001];

int main()
{
	arr[1] = 1; arr[2] = 2;
	int n;
	scanf("%d", &n);
	for (int i = 3; i <= n; ++i)
		arr[i] = (arr[i - 2] + arr[i - 1])%10007;

	printf("%d", arr[n]);
	return 0;
}