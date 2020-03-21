#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int w; bool isCheck = false;
	scanf("%d", &w);
	if (w>2&&(w-2) % 2 == 0)isCheck = true;
		
	if (isCheck)printf("YES");
	else printf("NO");
	return 0;
}