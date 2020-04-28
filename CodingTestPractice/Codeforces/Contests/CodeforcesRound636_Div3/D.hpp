#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

int min(std::initializer_list<int> list)
{
	return *min_element(list.begin(), list.end());
}

int max(std::initializer_list<int> list)
{
	return *max_element(list.begin(), list.end());
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		vector<int> pref(2 * m + 2);
		for (auto& i : arr)cin >> i;
		for (int i = 0; i < n / 2; ++i)
		{
			int nochange = arr[i] + arr[n - i - 1];
			int change1 = min({ arr[i], arr[n - i - 1]}) + 1;
			int change2 = max({ arr[i], arr[n - i - 1]}) + m + 1;
			pref[nochange]--;
			pref[nochange + 1]++;
			pref[change1]--;
			pref[change2]++;
		}
		int ans = n + 1;
		pref[0] = n;
		for (int i = 1; i < 2 * m + 2; ++i)
		{
			pref[i] = pref[i - 1] + pref[i];
			ans = min({ ans,pref[i] });
		}
		cout << ans << endl;

	}
}