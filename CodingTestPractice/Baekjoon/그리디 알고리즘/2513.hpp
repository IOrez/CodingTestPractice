#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, S;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K >> S;
	vector<pair<int, int>> table(N);
	for (int i = 0; i < N; ++i)
		cin >> table[i].first >> table[i].second;

	sort(table.begin(), table.end());
	long long sum = 0, firstCarryDis = 0;
	int cnt = 0;
	for (int i = 0; table[i].first < S && i < N;)
	{
		if (cnt == 0)firstCarryDis = S - table[i].first;
		if (K - cnt < table[i].second)
		{
			table[i].second -= (K - cnt);
			sum += firstCarryDis * 2ll;
			cnt = 0;
		}
		else
		{
			cnt += table[i].second;
			++i;
		}
	}
	sum += firstCarryDis * 2ll;
	cnt = 0;
	firstCarryDis = 0;
	for (int i = N - 1; table[i].first > S && i >= 0;)
	{
		if (cnt == 0)firstCarryDis = table[i].first - S;
		if (K - cnt < table[i].second)
		{
			table[i].second -= (K - cnt);
			sum += firstCarryDis * 2ll;
			cnt = 0;
		}
		else
		{
			cnt += table[i].second;
			--i;
		}
	}
	sum += firstCarryDis * 2ll;
	cout << sum;
	return 0;
}