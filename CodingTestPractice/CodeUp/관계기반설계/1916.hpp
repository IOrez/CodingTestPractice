#include <iostream>

#define MOD 10009
using namespace std;

int  DP[201];

int fibo(int n)
{
	if (n < 1)return 0;
	else if (n == 1)return 1;
	else if (DP[n] != 0)return DP[n];
	DP[n] = (fibo(n - 1) + fibo(n - 2)) % MOD;
	return DP[n];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	cout << fibo(N);
	return 0;
}