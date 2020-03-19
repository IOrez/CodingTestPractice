#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> v(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &v[i]);

	for (int i = 1; i < N; ++i)
		if (v[i] + v[i - 1] > v[i])v[i] = v[i] + v[i - 1];
	
	printf("%d", *std::max_element(std::begin(v), std::end(v)));
	return 0;
}