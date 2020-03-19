#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int en;
	int sn = 1;
	int sum = 0;
	scanf("%d", &en);
	while (sn <= en)
	{
		if(sn%2==0)
			sum += sn;
		sn++;
	}
	printf("%d", sum);
	return 0;
}