#include <iostream>
#include <string>
using namespace std;

char table[101][31];
int  D[101][31];
int cnt = -1;
void init(int N,int M)
{
	for (int i = N-1; i >= 0; i--)
	{
		for (int j = 0; j < M; ++j)
		{
			if (table[i][j] == 'X')
				D[i][j] = 0;
			else
				D[i][j] = D[i + 1][j] + 1;
		}
	}
}

void greedy(int S, int T,int N,int M)
{
	while (true)
	{
		if (S >= T)return;
		int max = 0;
		int idx = 0;
		for (int j = 0; j < M; ++j)
		{
			if (max < D[S - 1][j])
			{
				max = D[S - 1][j];
				idx = j;
			}
		}
		if (max == 0) { cnt = -1; return; }
		else
		{
			cnt+=1;
			S = S + D[S - 1][idx];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
		cin >> table[i];
	
	init(N, M);
	int S, T;
	cin >> S >> T;
	greedy(S, T, N, M);
	cout << cnt;
	return 0;
}