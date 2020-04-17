#include <iostream>

using namespace std;

int DP[41];

int fibonacchi(int n)
{
	if (n <= 1) { DP[n] = n; return DP[n]; }
	if (DP[n] != 0)return DP[n];
	DP[n] =  fibonacchi(n - 1) + fibonacchi(n - 2);
	return DP[n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	int result = fibonacchi(N);
	cout << result;

	return 0;
}