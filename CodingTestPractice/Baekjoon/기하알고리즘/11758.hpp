#include <iostream>

using namespace std;
int x[3], y[3];

int ccw() {
	int val = x[1] * y[2] + x[0] * y[1] + y[0] * x[2];
	val -= y[0] * x[1] + y[1] * x[2] + x[0] * y[2];
	return val;
}

int ccw2()
{
	int val = 0;
	if (x[0] == x[1])
	{
		if (x[2] == 0)
			val = 0;
		else if (x[2] > x[0])
			val = -1;
		else
			val = 1;
	}
	else
	{
		float m = (float)(y[1] - y[0]) / (x[1] - x[0]);
		float k = y[0] - m * x[0];

		int xdif = x[1] - x[0];
		if (m >= 0)
		{
			if (xdif > 0)
			{
				val = (y[2] == m * x[2] + k) ? 0 : ((y[2] < m * x[2] + k) ? 1 : -1);
			}
			else
			{
				val = (y[2] == m * x[2] + k) ? 0 : ((y[2] > m * x[2] + k) ? 1 : -1);
			}
		}
		else
		{
			if (xdif > 0)
			{
				val = (y[2] == m * x[2] + k) ? 0 : ((y[2] < m * x[2] + k) ? 1 : -1);
			}
			else
			{
				val = (y[2] == m * x[2] + k) ? 0 : ((y[2] > m * x[2] + k) ? 1 : -1);
			}
		}
	}

	return val;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 3; ++i) {
		cin >> x[i] >> y[i];
	}
	int val = ccw();
	if (val > 0)cout << "1";
	else if (val < 0)cout << "-1";
	else cout << "0";
	return 0;
}