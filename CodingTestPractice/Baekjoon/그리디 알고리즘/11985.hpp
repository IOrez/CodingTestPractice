#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, K;
long long DP[21001];
long long v[20001];
long long solution(int s, int e)
{
	long long* pVal = &DP[s];
	int size, Max = 0, Min = 0x7fffffff;
	long long box;
	if (s >= e)return 0;
	if (*pVal != -1)return *pVal;
	*pVal = 0x7fffffffffffffff;
	size = M < e - s + 1 ? M : e - s + 1;
	for (int i = 0; i < size; ++i)
	{
		Max = max((long long)Max, v[s + i]);
		Min = min((long long)Min, v[s + i]);
		box = 1LL * (i + 1) * (Max - Min) + K;
		*pVal = min(*pVal, box + solution(s + i + 1, e));
	}
	return *pVal;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		DP[i] = -1;
	}
	cout << solution(0, N);
	return 0;
}