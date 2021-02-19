#include <iostream>

using namespace std;

using ll = long long;

ll y, x;
int solution() {
	int cnt = 1;
	ll dis = y - x, cur = 1, step =1;
	bool a = false;
	while (true) {
		if (dis < cur + step)break;
		cur += step;
		if (a) {
			step += 1;
		}
		a = !a;
		cnt += 1;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		cin >> x >> y;
		cout << solution() << '\n';
	}
	return 0;
}