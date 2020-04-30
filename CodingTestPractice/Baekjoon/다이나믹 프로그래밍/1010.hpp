#include <iostream>
#include <string.h>
using namespace std;

int DP[30][30];

int solution(int N, int M)
{
	DP[1][0] = 1; DP[1][1] = 1;
	for (int i = 2; i <= M; ++i)
	{
		for (int j = 0; j <= i; ++j)
			if (j == 0 || j == i)DP[i][j] = 1;
			else DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
	}
	return DP[M][N];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int N, M;
		cin >> N >> M;
		int result = solution(N, M);
		cout << result<<endl;
	}
	return 0;
}