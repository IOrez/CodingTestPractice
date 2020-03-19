#include <cstdio>
#pragma warning(disable:4996)

int main()
{

	int n, sum = 0,i =0;
	scanf("%d", &n);
	while (sum < n)
	{
		i++;
		sum += i;
	}
	printf("%d", i);

	return 0;
}