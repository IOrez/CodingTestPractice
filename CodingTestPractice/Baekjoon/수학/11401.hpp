#include <iostream>

using namespace std;
#define MAX_N	4000001
#define MOD		1000000007
using ll = long long;
ll fac[MAX_N];

ll Pow(ll x, ll y) {
	ll ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= MOD;
		}
		ret *= x;
		ret %= MOD;
		y /= 2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N,K;
	cin >> N >> K;
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
		fac[i] = (fac[i - 1] * i) % MOD;
	ll rev1 = Pow(fac[K] , MOD - 2);
	ll rev2 = Pow(fac[N - K] , MOD - 2);
	cout << (fac[N] * rev1*rev2)% MOD;
	return 0;
}