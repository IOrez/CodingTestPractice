#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr int Size = 'Z' - 'A' + 1;

char Table[20][20];
bool alpha[Size];

int Max = 0;
bool isInRange(int r, int c, int n, int m)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

void solution(int r, int c,int n,int m,int cnt)
{
	if (Max < cnt)Max = cnt;
	int dy[4] = { -1,1,0,0 };
	int dx[4] = { 0,0,1,-1 };
	for (int i = 0; i < 4; ++i)
	{
		int n_r = r + dy[i];
		int n_c = c + dx[i];
		if (!isInRange(n_r, n_c, n, m))
			continue;
		if (alpha[Table[n_r][n_c] - 'A'])
			continue;
		alpha[Table[n_r][n_c] - 'A'] = true;
		solution(n_r, n_c, n, m,cnt+1);
		alpha[Table[n_r][n_c] - 'A'] = false;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int R, C;
	cin >> R >> C;
	cin.ignore();
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
			cin >> Table[i][j];
		cin.ignore();
	}
	alpha[Table[0][0] - 'A'] = true;
	solution(0, 0, R, C,1);
	cout << Max;

	return 0;
}