#include <iostream>

#define MOD 10007
using namespace std;

int DP[1001][10];

void solution(int N)
{
	for (int i = 0; i < 10; ++i)DP[1][i] = 1;
	for (int i = 2; i <= N; ++i)
	{
		int sum = 0;
		for (int j = 0; j < 10; ++j)
		{
			sum = (sum + DP[i-1][j]) % MOD;
			DP[i][j] = sum;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	solution(N);

	int sum = 0;
	for (int i = 0; i < 10; ++i)
		sum = (sum + DP[N][i]) % MOD;

	cout << sum;

	return 0;
}