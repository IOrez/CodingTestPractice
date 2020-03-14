#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996);
int main()
{
	int N;
	scanf("%d", &N);
	std::vector<std::pair<int,int>> v(N);
	for (size_t i = 0; i < v.size(); ++i)
	{
		int startTime, endTime;
		scanf("%d %d", &startTime, &endTime);
		v[i] = std::make_pair(-endTime, -startTime);
	}
	auto func = [](std::pair<int, int> obj1, std::pair<int, int> obj2)->bool
	{
		if (obj1.first < obj2.first)return true;
		else if (obj1.first == obj2.first && obj1.second < obj2.second)return true;
		else return false;
	};
	std::make_heap(std::begin(v), std::end(v), func);
	int startTime = 0, endTime = 0;
	int count = 0;
	while (!v.empty())
	{
		auto time = v.front();
		time.first *= -1; time.second *= -1;
		std::pop_heap(std::begin(v), std::end(v)); 
		v.pop_back();
		if (endTime <= time.second)
		{
			endTime = time.first;
			startTime = time.second;
			count++;
		}
	}
	printf("%d", count);
	return 0;
}