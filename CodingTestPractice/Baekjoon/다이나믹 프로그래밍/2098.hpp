#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 1000000001

int W[17][17];
int DP[17][1 << 17];
int N;

int m_cost( int node,int visited)
{
	if (visited == (1 << N) - 1)
		return W[node][1] ? W[node][1] : INF;

	int& ret = DP[node][visited];
	if (ret != -1)return ret;
	ret = INF;

	for (int i = 1; i <= N; ++i)
		if (W[node][i] != 0 && !(visited & (1 << (i-1))))
			ret = min(ret, m_cost(i, (visited | (1 << (i-1)))) + W[node][i]);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> W[i][j];
	memset(DP, -1, sizeof(DP));

	cout << m_cost(1, 1);

	return 0;
}