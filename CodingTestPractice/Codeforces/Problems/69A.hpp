#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum_x = 0, sum_y = 0, sum_z = 0;
	int n;
	cin >> n;
	while (n--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		sum_x += x; sum_y += y; sum_z += z;
	}

	if (sum_x != 0 || sum_y != 0 || sum_z != 0)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}