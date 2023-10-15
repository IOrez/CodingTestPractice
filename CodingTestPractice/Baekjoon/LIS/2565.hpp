#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<pair<int,int>> v;
int DP[501];

void Solution()
{
	for (int k = 0; k < v.size(); k++)
	{
		DP[k] = 1;
		for (int i = 0; i < k; i++)
		{
			if (v[i].second < v[k].second)
				DP[k] = max(DP[k], DP[i] + 1);
		}
	}
}

int Solution2()
{
	vector<int> vtemp;
	for (int i = 0; i < v.size(); i++)
	{
		int target = v[i].second;
		auto iter = lower_bound(vtemp.begin(), vtemp.end(), target);
		if (iter == vtemp.end())
		{
			vtemp.push_back(target);
		}
		else
		{
			*iter = target;
		}

	}

	return vtemp.size();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int a, b;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	Solution();

	/*
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
		ans = max(ans, DP[i]);
	cout << v.size() - ans;
	*/
	cout << v.size() - Solution2();
	return 0;
}