#include <cstdio>
#pragma warning(disable:4996)



int main()
{
	int M, N;
	scanf("%d%d", &M, &N);
	
	int pieces = M * N / 2;
	
	printf("%d", pieces);
	return 0;
}