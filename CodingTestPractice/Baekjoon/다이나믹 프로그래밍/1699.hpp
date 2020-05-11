#include <iostream>
#include <cmath>
#define INF 999999999

using namespace std;

int DP[100001];

void solution(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		int min = INF;
		for (int j = sqrt(i); j > 0; --j)
		{
			if (j * j > i)continue;
			min = min < DP[i - j * j] ? min : DP[i - j * j];
		}
		DP[i] = min + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	solution(N);
	cout << DP[N];
	return 0;
}