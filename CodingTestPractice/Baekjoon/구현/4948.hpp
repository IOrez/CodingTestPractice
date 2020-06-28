#include <iostream>

using namespace std;

enum Type
{
	UNKNOWN,
	PRIME,
	NOTPRIME,
};
constexpr int Size = 123456 * 2 + 1;
Type check[Size];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	check[1] = NOTPRIME;
	while (true)
	{
		cin >> n;
		if (n == 0)break;
		int cnt = 0;
		for (int i = n+1; i <= 2 * n; ++i)
		{
			if (check[i] == NOTPRIME)continue;
			if (check[i] == PRIME)cnt++;
			else
			{
				bool isPrime = true;
				for (int j = 2; j * j <= i && isPrime; ++j)
					isPrime = (bool)(i % j);
			
				if (isPrime)
				{
					for (int j = i; j <= 2 * n; j += i)
						check[j] = PRIME;
					cnt++;
				}
				else check[i] = NOTPRIME;
			}
		}
		cout << cnt << '\n';
	}

}