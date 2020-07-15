#include <iostream>
using namespace std;

unsigned long long table[16][16];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M, K;
	
	table[0][1] = 1;
	
	for (int i = 1; i <= 15; ++i)
		for (int j = 1; j <= 15; ++j)
			table[i][j] = table[i - 1][j] + table[i][j - 1];

	cin >> N >> M >> K;
	if (K == 0)cout << table[N][M];
	else
	{
		int Y = K / M + (bool)(K % M);
		int X = K - (Y - 1) * M;
	
		cout << table[Y][X] * table[N - Y + 1][M - X + 1];
	}
	return 0;

} 