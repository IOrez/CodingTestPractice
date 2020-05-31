#include <iostream>

using namespace std;

#define INF 999999
int DP[5001];

void solution(int n)
{
	for (int i = 1; i <= n; ++i)DP[i] = INF;
	for (int i = 3; i <= n; ++i)
	{
		int min = DP[i-3];
		if (i - 5 >= 0)min = min < DP[i - 5] ? min : DP[i - 5];
		if (min != INF)DP[i] = min + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	solution(N);
	if (DP[N] == INF)cout << "-1";
	else cout << DP[N];
	return 0;
}