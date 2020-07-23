#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define INF 999999999

int N, M;
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
pair<int, int> DP[50][50], table[50][50], S, F;
bool isInRange(int y, int x)
{
	return 0 <= y && y < N && 0 <= x && x < M;
}

void solution()
{
	priority_queue<pair<pair<int,int>,pair<int, int>>> que;
	que.push({ DP[S.first][S.second],S });
	while (!que.empty())
	{
		int a = -que.top().first.first;
		int b = -que.top().first.second;
		int posY = que.top().second.first;
		int posX = que.top().second.second;
		que.pop();
		if (DP[posY][posX] < pair<int,int>{a, b})continue;
		if (posY == F.first && posX == F.second)
			break;
		for (int i = 0; i < 4; ++i)
		{
			int yy = posY + dy[i], xx = posX + dx[i];
			if (!isInRange(yy, xx))continue;
			pair<int, int> next = { DP[posY][posX].first + table[yy][xx].first,DP[posY][posX].second};
			if (!table[yy][xx].first)next.second += table[yy][xx].second;
			if (next >= DP[yy][xx])continue;
			DP[yy][xx] = next;
			que.push({ {-DP[yy][xx].first,-DP[yy][xx].second}, { yy, xx } });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M; cin.ignore();
	for (int i = 0; i < N; ++i)
	{
		string input;
		getline(cin, input);
		for (int j = 0; j < M; ++j)
		{
			DP[i][j] = { INF,INF };
			if (input[j] == 'g')
			{
				table[i][j].first = 1;
				for (int d = 0; d < 4; ++d)
				{
					int yy = i + dy[d], xx = j + dx[d];
					if (!isInRange(yy, xx))continue;
					table[yy][xx].second = 1;
				}
			}
			else if (input[j] == 'F')F = { i,j };
			else if (input[j] == 'S')S = { i,j };
		}
	}
	table[S.first][S.second] = table[F.first][F.second] = { 0,0 };
	DP[S.first][S.second] = { 0,0 };

	solution();
	cout << DP[F.first][F.second].first << " " << DP[F.first][F.second].second<<'\n';
	return 0;
}