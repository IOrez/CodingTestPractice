#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> v;
multiset<int> mset;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int weight_limit;
		cin >> weight_limit;
		v.push_back(-weight_limit);
	}
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int box_weight;
		cin >> box_weight;
		mset.insert(-box_weight);
	}
	sort(v.begin(), v.end());
	int time = 0;
	while (!mset.empty())
	{
		time++;
		bool check = false;
		for (int i = 0; i < N; ++i)
		{
			auto iter = mset.lower_bound(v[i]);
			if (iter == mset.end())continue;
			check = true;
			mset.erase(iter);
		}
		if (!check)break;
	}
	if (!mset.empty())time = -1;
	cout << time;

	return 0;
}