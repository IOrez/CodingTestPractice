#include <cstdio>
#include <cmath>
#pragma warning(disable:4996)
int main()
{
	int val[5];
	for (int i = 0; i < 5; ++i)
	{
		scanf("%1d", val + i);
		printf("[%d]\n", (*(val + i))*(int)pow(10,4-i));
	}
	return 0;
}