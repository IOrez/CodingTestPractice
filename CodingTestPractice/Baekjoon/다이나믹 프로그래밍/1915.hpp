#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int N, M;
bool table[1001][1001];
int  DP[1001][1001];
int main()
{
	int Max = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &table[i][j]);
			DP[i][j] = table[i][j];
		}
	
	for(int i = 1;i<=N;++i)
		for (int j = 1; j <= M; ++j)
		{
			if (table[i][j])
			{
				DP[i][j] = min({ DP[i][j - 1],DP[i - 1][j],DP[i - 1][j - 1] }) + 1;
				Max = max({ DP[i][j],Max });
			}
		}

	printf("%d", Max * Max);
	return 0;
}