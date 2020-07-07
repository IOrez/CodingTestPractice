#include <iostream>

using namespace std;
int table[100];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> table[i];
			table[i] = abs(table[i]);
			if (i % 2 == 0)
				table[i] *= -1;
		}
		for (int i = 1; i <= n; ++i)
			cout << table[i] << '\n';
	}
	return 0;
}