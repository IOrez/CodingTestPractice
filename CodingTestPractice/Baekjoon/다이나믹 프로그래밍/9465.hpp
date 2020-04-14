#include <iostream>

using namespace std;

int table[2][100000];
int DP[2][100000];


void solution(int N)
{
	DP[0][0] = table[0][0];
	DP[1][0] = table[1][0];
	DP[0][1] = DP[1][0] + table[0][1];
	DP[1][1] = DP[0][0] + table[1][1];

	int val;
	for (int i = 2; i < N; ++i)
	{
		val = DP[1][i - 1] > DP[1][i - 2] ? DP[1][i - 1] : DP[1][i - 2];
		DP[0][i] = val + table[0][i];


		val = DP[0][i - 1] > DP[0][i - 2] ? DP[0][i - 1] : DP[0][i - 2];
		DP[1][i] = val + table[1][i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				cin >> table[i][j];

		solution(N);
		int val1 = DP[0][N - 1];
		int val2 = DP[1][N - 1];
		int val = val1 > val2 ? val1 : val2;
		cout << val <<"\n";

	}
	return 0;
}