#include <iostream>

using namespace std;

bool check[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 1; i <= 10000; ++i)
	{
		if (!check[i])cout << i << '\n';
		int sum = i,j = i;
		while (j != 0)
		{
			sum += j % 10;
			j /= 10;
		}
		if(sum<=10000)
			check[sum] = true;
	}
	return 0;
}