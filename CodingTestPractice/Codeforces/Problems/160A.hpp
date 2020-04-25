#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	sort(v.begin(), v.end(), greater<int>());
	int mySum = 0;
	int myCnt = 0;
	int twinSum = 0;
	int twinIdx = n - 1;
	for (int i = 0; i < twinIdx; ++i)
	{
		mySum += v[i];
		myCnt++;
		while (mySum > twinSum&&i<twinIdx)
		{
			twinSum += v[twinIdx];
			twinIdx--;
		}
	}
	if (mySum <= twinSum)myCnt++;
	cout << myCnt;
	return 0;
}