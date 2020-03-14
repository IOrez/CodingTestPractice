#include <cstdio>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_BUFFER_SIZE 2001
int main()
{
	char str[MAX_BUFFER_SIZE] = "";
	fgets(str, MAX_BUFFER_SIZE, stdin);
	printf("%s", str);
	return 0;
}