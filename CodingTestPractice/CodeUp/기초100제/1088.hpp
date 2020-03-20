#include <cstdio>
#pragma warning(disable:4996)


int main()
{
	int n;
	int i = 1;
	scanf("%d", &n);
	while (i <= n) {
		if(i%3!=0)
			printf("%d ", i);
		i++;
	}
}