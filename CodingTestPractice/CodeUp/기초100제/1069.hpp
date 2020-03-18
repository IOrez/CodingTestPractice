#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	char ch;
	scanf("%c", &ch);
	if (ch == 'A')printf("best!!!\n");
	else if (ch == 'B')printf("good!!\n");
	else if (ch == 'C')printf("run!\n");
	else if (ch == 'D')printf("slowly~\n");
	else printf("what?\n");
	return 0;
}