#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	char ch;
	char c = 'a';
	scanf("%c", &ch);
	while (c <= ch)
	{
		printf("%c ", c++);
	}

	return 0;
}