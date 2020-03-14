#include <cstdio>
#pragma warning(disable:4996)

#define MAX_BUFFER_SIZE	21
int main()
{
	char str[MAX_BUFFER_SIZE] = "";
	scanf("%s", str);
	int i = 0;
	while (str[i] != '\0')
		printf("\'%c\'\n", str[i++]);
	return 0;
}