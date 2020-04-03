#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000][3];
int table[1000][3];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (auto i = 0; i < N; ++i)
		cin>> table[i][0] >>  table[i][1] >>  table[i][2];
	
	DP[0][0] = table[0][0];
	DP[0][1] = table[0][1];
	DP[0][2] = table[0][2];

	for (int i = 1; i < N; ++i)
	{
		DP[i][0] = min({ DP[i - 1][1] ,DP[i - 1][2] }) + table[i][0];
		DP[i][1] = min({ DP[i - 1][0] ,DP[i - 1][2] }) + table[i][1];
		DP[i][2] = min({ DP[i - 1][0] ,DP[i - 1][1] }) + table[i][2];
	}

	int Minval = min({ DP[N - 1][0], DP[N - 1][1], DP[N - 1][2] });
	
	cout << Minval << endl;
	return 0;
}