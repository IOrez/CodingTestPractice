#include <iostream>
using namespace std;


int DP[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	int A = T / 300;
	T %= 300;
	int B = T / 60;
	T %= 60;
	int C = T / 10;
	T %= 10;
	if (T != 0)cout << -1;
	else cout << A << " " << B << " " << C;

	return 0;
}