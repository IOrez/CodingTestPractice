#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n;
	int cnt = 0;
	cin >> n;
	while (n--)
	{
		int pi, qi;
		cin >> pi >> qi;
		if (qi - pi >= 2)cnt++;
	}
	cout << cnt;
	return 0;
}