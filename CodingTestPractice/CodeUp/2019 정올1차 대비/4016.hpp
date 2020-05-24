#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << gcd(gcd(a, b), c);
	return 0;
}