#include <iostream>
#include <cmath>

using namespace std;

#define MAX_SIZE 1500002

int N;
long long DP[MAX_SIZE];
long long T[MAX_SIZE];
long long C[MAX_SIZE];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> C[i];
	}

	for (int i = N; i > 0; i--)
	{
		if (i + T[i] - 1 > N) DP[i] = DP[i + 1];
		else DP[i] = max(DP[i + 1], DP[i + T[i]] + C[i]);
	}

	cout << DP[1];

	return 0;
}