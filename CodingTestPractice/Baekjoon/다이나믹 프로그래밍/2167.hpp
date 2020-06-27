#include <iostream>

using namespace std;

int table[301][301];
int DP[301][301];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, M, K;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			cin >> table[i][j];
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1]  + table[i][j];
		}
	cin >> K;
	while (K--)
	{
		int sx, sy, ex, ey,sum = 0;
		cin >> sy >> sx >> ey >> ex;
		cout << DP[ey][ex] - DP[ey][sx - 1] - DP[sy - 1][ex] + DP[sy - 1][sx - 1]<<'\n';
	}
	return 0;
}