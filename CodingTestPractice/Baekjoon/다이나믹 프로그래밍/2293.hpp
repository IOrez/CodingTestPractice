#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[10001];

void solution(vector<int>& v,int k)
{
	DP[0] = 1;
	for (auto value : v)
		for (int i = value; i <= k; ++i)
			DP[i] += DP[i - value];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)cin >> v[i];
	sort(v.begin(), v.end());

	solution(v, k);

	cout << DP[k];

	return 0;
}