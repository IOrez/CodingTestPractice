#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#pragma warning(disable:4996)

using namespace std;

using pll = pair<long long, long long>;
using vp = vector<pll>;
multiset<int> Set;


int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	vp vec(N);
	for (auto i = 0; i < N; ++i)
		scanf("%ld%ld", &vec[i].first, &vec[i].second);

	for (auto i = 0; i < K; ++i)
	{
		long long C;
		scanf("%ld", &C);
		Set.insert(C);
	}

	auto cmp = [&](pll obj1, pll obj2)->bool {
		if (obj1.second > obj2.second)return true;
		else return false;
	};


	sort(vec.begin(), vec.end(), cmp);

	long long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		auto iter = Set.lower_bound(vec[i].first);
		if (iter == Set.end())continue;
		sum += vec[i].second;
		Set.erase(Set.equal_range(*iter).first);
	}

	printf("%ld", sum);
	
	return 0;
}