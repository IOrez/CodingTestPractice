#include <iostream>

using namespace std;

#define MOD		10007

int DP[1001];

void solution(int n)
{
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i <= n ; ++i)
		DP[i] = ((2 * DP[i - 2])% MOD + DP[i - 1])% MOD;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	solution(n);
	cout << DP[n];
	return 0;
}