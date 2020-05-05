#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 99999999

unsigned int Table[101][101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
		{
			if(i==j)continue;
			Table[i][j] = INF;
		}



	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		Table[a][b] = 1;
		Table[b][a] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				int a = Table[i][j];
				int b = Table[i][k] + Table[k][j];
				Table[i][j] = a < b ? a : b;
			}
		}
	}
	
	int max_c = INF;
	int idx = -1;
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		for (int j = 1; j <= N; ++j)
			sum += Table[i][j];

		if (max_c > sum)
		{
			max_c = sum;
			idx = i;
		}
	}
	cout << idx;

	return 0;
}