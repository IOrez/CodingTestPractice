#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1)return false;
	bool check = true;
	for (int i = 2; i * i <= n && check; ++i)
		check = n % i != 0;
	return check;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, Cnt = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int number; cin >> number;
		if (isPrime(number))Cnt++;
	}
	cout << Cnt;

	return 0;
}