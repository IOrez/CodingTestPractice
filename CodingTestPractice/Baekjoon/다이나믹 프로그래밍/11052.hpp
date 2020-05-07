#include <iostream>

using namespace std;

int DP[10001];
int Table[10001];


void solution(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		DP[i] = Table[i];
		for (int j = i; j >= 1; --j)
			if (DP[i] < DP[i - j] + Table[j])DP[i] = DP[i - j] + Table[j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Table[i];
	solution(N);

	cout << DP[N];
	return 0;
}