#include <cstdio>
#pragma warning(disable:4996)

int n[10001];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
	{
		int k;
		scanf("%d", n+i); 
	}
	for (int i = num - 1; i >= 0;--i)
	{
		printf("%d ", n[i]);
	}
	return 0;
}