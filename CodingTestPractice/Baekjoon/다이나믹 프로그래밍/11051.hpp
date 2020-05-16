#include <iostream>

#define MOD 10007
using namespace std;

int DP[1001][1001];

void solution(int N)
{
	DP[0][0] = 1;
	for (int i = 1; i <= N; ++i)
	{
		DP[i][0] = 1;
		DP[i][i] = 1;
		for (int j = 1; j < i; ++j)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i-1][j])%MOD;		
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,K;
	cin >> N >> K;
	solution(N);
	cout << DP[N][K];
	return 0;
}