#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	char ch;
	while ((ch = getc(stdin)) != 'q')
	{
		printf("%c\n", ch);
		getchar();
	}
	printf("%c\n", ch);
	return 0;
}