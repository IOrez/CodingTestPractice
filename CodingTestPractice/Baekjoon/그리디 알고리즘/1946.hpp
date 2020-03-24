#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

int main()
{
	int testCase;
	scanf("%d", &testCase);
	for (int test = 1; test <= testCase; ++test)
	{
		int n;
		scanf("%d", &n);
		int count = 1;
		std::vector<std::pair<int,int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			v[i]= { a,b };
		}
		std::sort(std::begin(v), std::end(v));
		int val = v[0].second;
		for (auto i = 1; i < v.size(); ++i)
			if (v[i].second < val) { val = v[i].second; count++; }

		printf("%d\n", count);
		v.clear();
	}
	return 0;
}