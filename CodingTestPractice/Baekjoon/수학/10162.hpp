#include <iostream>

using namespace std;

int N;
int cnt[3];
int main() {
	cin >> N;
	cnt[0] = N / 300; N %= 300;
	cnt[1] = N / 60; N %= 60;
	cnt[2] = N / 10; N %= 10;

	if (N != 0)cout << -1;
	else
		for (int i = 0; i < 3; ++i)cout << cnt[i] << ' ';
	return 0;
}