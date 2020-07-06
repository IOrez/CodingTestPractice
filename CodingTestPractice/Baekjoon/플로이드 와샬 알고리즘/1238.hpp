#include <iostream>
#include <algorithm>
using namespace std;

int table[1001][1001];

#define INF	1000000

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M, X, S, E, T;
	cin >> N >> M >> X;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (i == j)continue;
			else table[i][j] = INF;

	while (M--)
	{
		cin >> S >> E >> T;
		table[S][E] = T;
	}

	int Max = -1;
	for(int k =1;k<=N;++k)
		for(int i = 1;i<=N;++i)
			for (int j = 1; j <= N; ++j)
				table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
		
	for (int i = 1; i <= N; ++i)
		Max = max({ Max, table[i][X] +table[X][i] });
	cout << Max;

	return 0;
}