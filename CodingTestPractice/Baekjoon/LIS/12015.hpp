#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int Solution()
{
	vector<int> vtmp;
	for (int i = 0; i < v.size(); i++)
	{
		int target = v[i];
		auto iter = lower_bound(vtmp.begin(), vtmp.end(), target);

		if (iter != vtmp.end())
			*iter = target;
		else
			vtmp.push_back(target);
	}

	return vtmp.size();
}

int main()
{
	int N ,a;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	int ans = Solution();

	cout << ans;

	return 0;
}