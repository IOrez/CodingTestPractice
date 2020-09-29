#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iomanip>
using namespace std;

using plf = pair<double, double>;

int N;

double ccw(plf& point1, plf& point2, plf& point3) {
	double x1 = point1.first, y1 = point1.second;
	double x2 = point2.first, y2 = point2.second;
	double x3 = point3.first, y3 = point3.second;
	return (x2 * y3 + x1 * y2 + y1 * x3) - (y1 * x2 + y2 * x3 + x1 * y3);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<plf> v(N);
	for (auto& i : v)
		cin >> i.first >> i.second;

	double S = 0.0f;
	for (int i = 1; i < N - 1; ++i) {
		S += ccw(v[0], v[i], v[i + 1]);
	}
	S = abs(S) / 2;
	cout <<fixed<<setprecision(1)<< roundl(S * 10) / 10;
	return 0;
}