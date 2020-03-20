#include <cstdio>
#pragma warning(disable:4996)


int main()
{
	int n;
	int sum = 0;
	int i = 1;
	scanf("%d", &n);
	while (sum < n) { sum += i; i++; }
	printf("%d", sum);
}