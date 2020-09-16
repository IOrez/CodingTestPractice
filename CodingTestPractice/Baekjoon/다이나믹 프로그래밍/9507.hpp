#include <iostream>

using namespace std;

unsigned long long DP[68];


unsigned long long koong(int n) {
	if (DP[n] != 0)return DP[n];
	if (n < 2)return 1;
	else if (n == 2)return 2;
	else if (n == 3)return 4;
	DP[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	return DP[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase; cin >> testCase;
	int n;
	while (testCase--) {
		cin >> n;
		cout << koong(n) << '\n';
	}
	return 0;
}