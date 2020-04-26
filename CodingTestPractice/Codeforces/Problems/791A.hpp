#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (a <= b)
	{
		cnt++;
		a *= 3;
		b *= 2;
	}
	cout << cnt;
	return 0;
}