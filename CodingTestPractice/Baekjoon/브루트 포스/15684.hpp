#include <iostream>
#include <limits>
using namespace std;

int Table[30][20];
int Min = numeric_limits<int>::max();


void solution(int r,int c,int N, int H, int cnt)
{
	bool check = true;
	for (int i = 0; i < N; ++i)
	{
		int c = i;
		for (int j = 0; j < H; ++j)
			c += Table[j][c];
		if (c != i) {check = false; break; }
	}
	if (check&&cnt<=3&&Min>cnt) {Min = cnt;}
	else if(cnt<3)
	{
		for (int i = r; i < H; ++i) 
		{
			for (int j = 0; j < N-1; ++j)
			{
				if (Table[i][j]!=0||Table[i][j+1]!=0)continue;

				Table[i][j] = 1;
				Table[i][j + 1] = -1;
				solution(i, j, N, H, cnt + 1);
				Table[i][j] = 0;
				Table[i][j + 1] = 0;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M, H;
	cin >> N >> M >> H;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		Table[a - 1][b - 1] = 1;
		Table[a - 1][b] = -1;
	}
	solution(0, 0, N, H, 0);
	if (Min > 3)cout << -1;
	else cout << Min;
	return 0;
}