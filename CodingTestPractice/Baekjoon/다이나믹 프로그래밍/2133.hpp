#include <iostream>

using namespace std;

unsigned long long DP[31];

void solution(int n)
{
	DP[0] = 1;
	for (int i = 2; i <= n;i+=2)
	{
		if (i - 2 >= 0)DP[i] += 3 * DP[i - 2];
		for (int j = 4; j <= i; j += 2)
			if (i - j >= 0)DP[i] += 2 * DP[i - j];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	solution(n);
	cout << DP[n];
	return 0;
}