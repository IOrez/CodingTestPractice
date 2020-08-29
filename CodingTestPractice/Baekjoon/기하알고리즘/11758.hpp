#include <iostream>

using namespace std;
int x[3], y[3];

int ccw() {
	int val = x[1] * y[2] + x[0] * y[1] + y[0] * x[2];
	val -= y[0] * x[1] + y[1] * x[2] + x[0] * y[2];
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