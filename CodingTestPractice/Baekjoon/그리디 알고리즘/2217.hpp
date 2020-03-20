#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>
#pragma warning(disable:4996)



int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);

	std::make_heap(std::begin(v), std::end(v));
	int count = 0;
	int result = std::numeric_limits<int>::min();
	while (!v.empty())
	{
		int val = v.front();
		count++;

		val = val * count;
		if (result < val)result = val;
		std::pop_heap(std::begin(v), std::end(v));
		v.pop_back();
	}

	printf("%d",result);


	return 0;
}