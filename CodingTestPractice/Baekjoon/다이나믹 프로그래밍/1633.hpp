#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][16][16];

#pragma warning(disable:4996)

vector<pair<int, int>>v;
int solution(int d,int w,int b)
{
	if (d == v.size())return 0;
	int& ret = dp[d][w][b];
	if (ret != -1)return ret;

	if (w > 0)
		ret = max(ret, solution(d + 1, w - 1, b) + v[d].first);
	if (b > 0)
		ret = max(ret, solution(d + 1, w, b - 1) + v[d].second);

	ret = max(ret, solution(d + 1, w, b));
	return ret;
}
int main()
{
	int a, b;
	
	while (scanf("%d %d",&a,&b) > 0)
		v.push_back({ a,b });

	memset(dp, -1, sizeof(dp));
	cout << solution(0, 15, 15);
	return 0;
}