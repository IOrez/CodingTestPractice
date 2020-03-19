#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	char i, j = 0;
	scanf("%c", &i);
	for (j = 1; j <= 15; ++j)
		printf("%C*%0X=%0X\n",i,j,((i-'A'+10)*j));

	return 0;
}