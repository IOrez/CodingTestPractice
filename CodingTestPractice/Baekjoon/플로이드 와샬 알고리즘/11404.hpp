#include <iostream>


using namespace std;

int table[101][101];
#define INF	999999999

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M,start,end,weight;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if(i!=j) table[i][j] = INF;
	
	for (int i = 0; i < M; ++i)
	{
		cin >> start >> end >> weight;
		if(table[start][end]>weight) table[start][end] = weight;
	}
	
	for (int k = 1; k <= N; ++k)
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				if (table[i][j] > table[i][k] + table[k][j])
					table[i][j] = table[i][k] + table[k][j];
			
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (table[i][j] == INF)table[i][j] = 0;
			cout << table[i][j] << " ";
		}
		cout << '\n';
	}
	


	return 0;
}