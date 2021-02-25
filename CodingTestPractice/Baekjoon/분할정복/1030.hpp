#include <iostream>
#include <cmath>

using namespace std;

int const TABLE_SIZE = 50;

int S, N, K, R1, R2, C1, C2;
int table[TABLE_SIZE][TABLE_SIZE];

int solution(int s,long long r,long long k,int y,int x) {

	if (s == 0)return 0;

	int bx = (r - k) / 2; int by = (r - k) / 2;
	if (by <= y && y < by + k && bx <= x && x < bx + k)return 1;

	r /= N;
	k /= N;

	return solution(s - 1, r, k, y % r, x % r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	long long r = pow(N, S);
	long long k = K;
	for (int i = 1; i < S; ++i)k *= N;

	for(int i =R1;i<=R2;++i)
		for (int j = C1; j <= C2; ++j)
			table[i - R1][j - C1] = solution(S, r, k, i, j);

	for (int i = R1; i <= R2; ++i){
		for (int j = C1; j <= C2; ++j)
			cout << table[i - R1][j - C1];
		cout << '\n';
	}

	return 0;
}