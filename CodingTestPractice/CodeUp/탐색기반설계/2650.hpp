#include <iostream>
#include <algorithm>
using namespace std;

int num[3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 3; ++i)
		cin >> num[i];

	int Min = 10001;
	for (int i = 0; i < 3; ++i)
		Min = min(num[i], Min);

	int Max = -1;
	for (int i = 1; i <= Min; ++i)
	{
		bool check = true;
		for (int j = 0; j < 3 && check; ++j)
			check = (num[j] % i == 0);
		if (check)Max = max(Max, i);
	}
	cout << Max;
	return 0;
}