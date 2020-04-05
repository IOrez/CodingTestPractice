#include <iostream>

using namespace std;

int DP[11];

void init()
{
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 2; i < 11; ++i)
	{
		int val = DP[i];
		if (i > 1)val += DP[i - 1];
		if (i > 2)val += DP[i - 2];
		if (i > 3)val += DP[i - 3];
		DP[i] = val;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	init();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << DP[n] << endl;
	}


	return 0;
}