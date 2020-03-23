#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

int main()
{
	int testCase = 0;
	char str[101];
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test)
	{
		scanf("%s", str);
		int len = strlen(str);
		if (len > 10) printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
		else printf("%s\n", str);
	}
	return 0;
}