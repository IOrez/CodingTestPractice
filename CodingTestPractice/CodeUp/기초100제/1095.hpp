#include <cstdio>
#pragma warning(disable:4996)

int n[10001];
int main()
{
	int num;
	int min = 24;
	scanf("%d", &num);
	for (int i = 0; i < num; ++i)
	{
		int k;
		scanf("%d", &k);
		if (min > k)min = k;
	}
	
	printf("%d ", min);
	
	return 0;
}