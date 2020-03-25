#include <cstdio>
#pragma warning(disable:4996)

void print(int n,int max_n)
{
	if (n > max_n)return;
	printf("%d\n", n);
	print(n + 1, max_n);
}

int main()
{
	int n;
	scanf("%d", &n);
	print(1, n);
	return 0;
}