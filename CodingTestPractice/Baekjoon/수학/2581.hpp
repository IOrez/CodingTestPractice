#include <iostream>

using namespace std;

int sNum, eNum;

bool check[10001];

bool isPrime(int n)
{
	if (n <= 1)
		return false;

	bool check = true;
	for (int i = 2; i * i <= n && check; i++)
		check = (n % i) != 0;

	return check;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> sNum >> eNum;

	int ans = 0;
	int nMin = eNum + 1;
	for (int i = sNum; i <= eNum; i++)
	{
		if (i ==  1)
			continue;

		if (check[i] == true)
			continue;

		check[i] = true;

		bool bIsPrime = isPrime(i);

		if (bIsPrime)
		{
			ans += i;
			if(nMin == eNum + 1)
				nMin = i;
		}

		for (int j = 2; i * j <= eNum; j++)
			check[i * j] = true;
	}

	if (nMin == eNum + 1)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", ans);
		printf("%d\n", nMin);
	}
}