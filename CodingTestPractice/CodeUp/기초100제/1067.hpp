#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n;
	scanf("%d", &n );
	
	if (n > 0)printf("plus\n");
	else printf("minus\n");
	
	if (n% 2 == 0)printf("even\n");
	else printf("odd\n");
	


	return 0;
}