#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int DP[100001];
#define INF 999999
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 1; i <= 10000; ++i)DP[i] = INF;
	for (int i = 1; i <= N; ++i)
	{
		int val;
		cin >> val;
		v.push_back(val);
		DP[val] = 0;
	}

	sort(v.begin(), v.end());
	for (int i = 1; i <= 10000; ++i)
	{
		int Min = DP[i];
		for (auto j = 0; j < N; ++j)
		{
			int lastIdx = i - v[j];
			if (lastIdx > 0)Min = Min > DP[lastIdx] ? DP[lastIdx] : Min;
			else break;
		}
		if (Min != INF) DP[i] = Min + 1;
	}
	if (DP[K] == INF)DP[K] = -1;
	cout << DP[K];
	return 0;
}