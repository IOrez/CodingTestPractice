#include <iostream>

using namespace std;

int table[501][501];
int DP[501][501];

int dynamicProgramming(int N)
{
	DP[1][1] = table[1][1];
	int MaxVal = DP[1][1];
	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1)DP[i][j] = DP[i - 1][j] + table[i][j];
			else if (j == i)DP[i][j] = DP[i - 1][j - 1] + table[i][j];
			else
			{
				MaxVal = DP[i - 1][j - 1] > DP[i - 1][j] ? DP[i - 1][j - 1] : DP[i - 1][j];
				DP[i][j] = MaxVal + table[i][j];
			}
		}
	}
	MaxVal = -1;
	for (int j = 1; j <= N; ++j)
		if (MaxVal < DP[N][j])MaxVal = DP[N][j];

	return MaxVal;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> table[i][j];

	cout << dynamicProgramming(N);


	return 0;
}