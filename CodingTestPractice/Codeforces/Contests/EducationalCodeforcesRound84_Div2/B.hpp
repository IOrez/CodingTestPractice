#include <cstdio>
#pragma warning(disable:4996)

bool flag, g[100001];

int main()
{
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)g[i] = false;
		int xi = -1, yi;
		for (int i = 1; i <= n; ++i)
		{
			int lineNum;
			scanf("%d", &lineNum);
			flag = false;
			for (int j = 0; j < lineNum; ++j)
			{
				int k; 
				scanf("%d",&k);
				if (!flag && !g[k])flag = g[k] = true;
			}
			if (!flag&&xi==-1)xi = i;
		}
		if (xi != -1)
		{
			for (int i = 1; i <= n; ++i)if (!g[i]) { yi = i; break; }
			printf("IMPROVE\n%d %d\n", xi, yi);
		}
		else printf("OPTIMAL\n");
	}
	return 0;
}