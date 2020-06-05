#include <iostream>
#include <cmath>
using namespace std;


int  col[15];
int  cnt;
void solution(int r,int N)
{
	if (r == N)cnt++;
	else
		for (int j = 0; j < N; ++j)
		{
			col[r] = j;
			bool check = false;
			for (int i = 0; i < r&&!check; ++i)
				if (col[i] == col[r] || abs(col[i] - col[r]) == abs(i - r))
					check = true;
			
			if(!check)
				solution(r + 1, N);
		}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	solution(0, N);
	cout << cnt;
	return 0;
}