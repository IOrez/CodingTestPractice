#include <iostream>
#include <climits>
#include <vector>
using namespace std;

using ll = long long;

int table[1001];
int cor[1001];
int group[1001];
int dp[1001];

ll solution(int start,int end)
{
	if (start > end)return 0;

	ll result = 0;
	int Max = -1, Max_Idx;
	int Min = INT_MAX, Min_Idx;
	vector<int> v;
	for (int i = start; i <= end; ++i)
	{
		int dif = cor[i] - table[i];
		if (dif < 0)group[i] = -1;
		else if (dif > 0)group[i] = 1;
		else
		{
			v.push_back(i);
			group[i] = 0;
		}
	}
	if (!v.empty())
	{
		int s = start;
		for (auto i : v)
		{
			result += solution(s, i - 1);
			s = i + 1;
		}
		result += solution(s, end);
	}
	else
	{
		dp[start] = 1;
		Max_Idx = start;
		for (int i = start + 1; i <= end; ++i)
		{
			dp[i] = 1;
			if (group[i] == group[i - 1])dp[i] += dp[i - 1];
			if (Max < dp[i])
			{
				Max = dp[i];
				Max_Idx = i;
			}
		}
		for (int i = Max_Idx - dp[Max_Idx] + 1; i <= Max_Idx; ++i)
			if (Min > abs(cor[i] - table[i]))
			{
				Min = abs(cor[i] - table[i]);
				Min_Idx = i;
			}
		for (int i = Max_Idx - dp[Max_Idx] + 1; i <= Max_Idx; ++i)
			if (group[i] < 0)
				table[i] -= Min;
			else if (group[i] > 0)
				table[i] += Min;
		result += Min;
		result += solution(start, Min_Idx - 1);
		result += solution(Min_Idx + 1, end);
	}
	
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> table[i];
	for (int i = 1; i <= N; ++i)
		cin >> cor[i];
	cout << solution(1, N);
	return 0;
}