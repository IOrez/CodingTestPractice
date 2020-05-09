#include <iostream>

#define MOD 1000000007
using namespace std;


unsigned long long solution(int n,int k)
{
	if (k == 0)return 1;
	
	unsigned long long Val = solution(n, k / 2);

	if (k % 2 == 1)
		return (Val* Val % MOD) * n % MOD;
	else
		return (Val*Val) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	cout << solution(n, k);
	return 0;
}