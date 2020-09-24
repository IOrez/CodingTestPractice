#include <iostream>
using namespace std;
long long num;
int cnt[10];

int main() {
	ios_base::sync_with_stdio(false);
	long long res = 1;
	for (int i = 0; i < 3; ++i) {
		cin >> num;
		res *= num;
	}
	while (res != 0) {
		cnt[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; ++i) {
		cout << cnt[i] << '\n';
	}

	return 0;
}