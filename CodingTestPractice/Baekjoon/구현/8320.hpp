#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			if (i * j > n)break;
			else cnt++;
	cout << cnt;
	return 0;
}