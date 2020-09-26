#include <iostream>

using namespace std;

using ull = unsigned long long;

#define LIMIT	100000000000000000

typedef struct bigInteger {
	ull high;
	ull low;
	bigInteger() :high(0), low(0) {};
	bigInteger(ull a_high, ull a_low) :high(a_high), low(a_low) {};
	struct bigInteger operator+(struct bigInteger obj) {
		struct bigInteger result;
		result.high = this->high + obj.high;
		result.low = this->low + obj.low;
		if (result.low > LIMIT) {
			result.high++;
			result.low -= LIMIT;
		}
		return result;
	}

}BigInteger;

BigInteger DP[101][101];


ostream& operator<<(ostream& os,BigInteger obj) {
	if (obj.high) {
		os << obj.high;
		ull tmpLow = obj.low;
		ull tmp = 0;
		while(tmpLow) {
			tmp++;
			tmpLow /= 10;
		}
		for (int i = 17 - tmp; i > 0; --i)
			os << 0;
	}
	os << obj.low;
	return os;
}


BigInteger C(int N, int M) {
	if (DP[N][M].high != 0||DP[N][M].low!=0)return DP[N][M];
	if (M == 0 || N == M)return BigInteger(0,1);
	DP[N][M] = C(N - 1, M - 1) + C(N - 1, M);
	return DP[N][M];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	BigInteger result = C(n, m);
	cout << result;
	return 0;
}