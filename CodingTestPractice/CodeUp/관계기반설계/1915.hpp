#include <iostream>

using namespace std;

int DP[21];

int fibonacci(int N)
{
	if (N <= 1) { DP[N] = N; return DP[N]; }
	if (DP[N] != 0)return DP[N];
	DP[N] = fibonacci(N - 1) + fibonacci(N - 2);
	return DP[N];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int result = fibonacci(n);
	cout << result;
	return 0;
}