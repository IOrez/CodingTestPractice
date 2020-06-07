#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t,x1, y1, x2, y2, r1, r2, Distance;
	cin >> t;
	while (t--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		Distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if (Distance == 0)
		{
			if (r1 == r2)cout << -1 << '\n';
			else cout << 0 << '\n';
		}
		else
		{
			if (Distance == (r1 + r2) * (r1 + r2) || Distance == (r1 - r2) * (r1 - r2))cout << 1 << '\n';
			else if (Distance > (r1 + r2) * (r1 + r2) || Distance <(r1 - r2) * (r1 - r2))cout << 0 << '\n';
			else cout <<2 << '\n';
		}
	}
	return 0;
}