#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false); cin.tie(NULL);
	unsigned long long int N, M, cnt =1;
	cin >> N >> M;
	if (N < 3)
	{
		if (N > 1)
		{
			cnt += (M - 1) / 2;
			if (cnt > 4)cnt = 4;
		}
	}
	else
	{
		if (M < 2)cnt = 1;
		else if (M < 3)cnt = 2;
		else if (M < 4)cnt = 3;
		else if (M < 7)cnt = 4;
		else
		{
			cnt = 3;
			cnt += (M - 5);
		}
	}
	cout << cnt;
	return 0;
}