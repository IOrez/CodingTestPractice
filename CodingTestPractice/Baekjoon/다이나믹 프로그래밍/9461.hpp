#include <iostream>

using namespace std;

unsigned long long DP[101];

void solution(int n)
{
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;
	for (int i = 6; i <= n; ++i)
		DP[i] = DP[i - 1] + DP[i - 5];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		solution(N);
		cout << DP[N]<<"\n";
	}
	return 0;
}