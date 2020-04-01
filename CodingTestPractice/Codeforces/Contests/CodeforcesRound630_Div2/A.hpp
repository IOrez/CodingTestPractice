#include <cstdio>
#pragma warning(disable:4996)

typedef struct point
{
	int x;
	int y;
}POINT;

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x, y, x1, y1, x2, y2;
		scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);

		bool result = true;
		int rx = x,ry = y;
	
		if (x1 == x2 && (a > 0 || b > 0))result = false;
		if (a > b) 
			if (x - x1 < 1)result = false;

		if (b > a)
			if (x2 - x < 1)result = false;

		/*if (a == b)
			if (x - x1 < 1 && x2 - x < 1)result = false;*/
		
		if (y1 == y2 && (c > 0 || d > 0))result = false;
		if (c > d) 
			if (y - y1 < 1)result = false;

		if (d > c)
			if (y2 - y < 1)result = false;
		
		/*if (c == d)
			if (y - y1 < 1 && y2 - y < 1)result = false;*/

		rx += (-1 * a) + b;
		ry += (-1 * c) + d;

		if (x1 > rx || x2<rx || y1>ry || ry > y2)result = false;

		if (!result)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}