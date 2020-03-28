#include <cstdio>
#pragma warning(disable:4996)

unsigned long long arr[100001];

void init()
{
	arr[2] = 1;
	for (int i = 3; i < 100001; ++i)
		arr[i] = arr[i - 1] + i - 1;
}
int main()
{
	int testCase;
	scanf("%d", &testCase);
	init();
	for (int test = 1; test <= testCase; ++test)
	{
		int num, order;
		scanf("%d%d", &num, &order);
		bool isCheck = false;
		while (num > 2)
		{
			if (arr[num - 1] >= order)
				printf("a");
			else
			{
				printf("b");
				isCheck = true;
				num--;
				break;
			}
			num--;
		}
		if (num == 2 && !isCheck)
			printf("bb");
		else
		{
			int i = order - arr[num];
			for (int k = num; k >= 1; --k)
			{
				if (k == i)printf("b");
				else printf("a");
			}
		}
		printf("\n");
	}
	return 0;
}