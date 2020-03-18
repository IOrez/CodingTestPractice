#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n[3];
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d", n + i);
		if (n[i] % 2 == 0)printf("even\n");
		else printf("odd\n");
	}
	return 0;
}