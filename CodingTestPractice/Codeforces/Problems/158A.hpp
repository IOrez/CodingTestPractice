#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector<int> v(n+1);
	for (auto i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	
	std::sort(std::begin(v)+1, std::end(v), [](int a, int b)->bool {return a > b; });

	int pivot_val = v[k];

	int num;
	for (num = 1; num <= n; ++num)
	{
		if (v[num] == 0)break;
		if (v[num] < pivot_val)break;
	}
	printf("%d", --num);
	return 0;
}