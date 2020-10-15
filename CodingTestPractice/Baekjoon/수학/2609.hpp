#include <iostream>

using namespace std;

int N1,N2;

int gcd(int n, int d) {
	if (d == 0)return n;
	else return gcd(d, n%d);
}

int lcm(int n1, int n2) {
	return n1 * n2 / gcd(n1, n2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N1>>N2;
	if (N1 < N2)swap(N1, N2);
	cout << gcd(N1, N2) << '\n';
	cout << lcm(N1, N2) << '\n';
	return 0;
}