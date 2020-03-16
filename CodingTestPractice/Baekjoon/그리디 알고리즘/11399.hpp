#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)


int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> v(n);
	std::vector<int> v2(n);
	for (size_t i = 0; i < v.size(); ++i)
	{
		int time;
		scanf("%d", &time);
		v[i] = -time;
	}
	std::make_heap(std::begin(v), std::end(v));

	int sum = 0;
	while (!v.empty())
	{
		static int idx = 0;
		sum = -v.front()+sum;
		std::pop_heap(std::begin(v),std::end(v));
		v.pop_back();
		v2[idx++] = sum;
	}

	sum = 0;
	std::for_each(std::begin(v2), std::end(v2), [&](int val) {
		sum += val;
	});
	
	printf("%d", sum);
	return 0;
}