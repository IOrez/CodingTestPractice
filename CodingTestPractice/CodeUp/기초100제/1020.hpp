#include<cstdio>
#pragma warning(disable:4996)

#define BUFFER_SIZE	13
int main()
{
	int first,second;
	scanf("%d-%d", &first, &second);
	printf("%06d%06d", first, second);
	return 0;
}