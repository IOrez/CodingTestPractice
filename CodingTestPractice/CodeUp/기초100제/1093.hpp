#include <cstdio>
#pragma warning(disable:4996)

int n[24];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
	{
		int k;
		scanf("%d", &k); ++n[k];
	}
	for (int i = 1; i <= 23; ++i)printf("%d ", n[i]);
	return 0;
}