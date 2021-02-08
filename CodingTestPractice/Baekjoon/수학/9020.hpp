#include <iostream>
#include <utility>
#include <cmath>
using namespace std;


enum class type {
	UNKNOWN, PRIME, NOTPRIME
};

#define SIZE 10001
#define ERROR	-1

type eType[SIZE];
int testCase,n;
void init() {
	for (int i = 2; i < SIZE; ++i) {
		if (eType[i] == type::NOTPRIME)continue;
		eType[i] = type::PRIME;
		for (int j = i * 2; j < SIZE; j += i)
			eType[j] = type::NOTPRIME;
	}
}

pair<int, int> solution(int N) {
	pair<int, int> result = { ERROR, ERROR };

	int pivot = N / 2;
	for (int i = 0; i < N / 2 - 1; ++i) {
		if (eType[pivot - i] != type::PRIME || eType[N - (pivot - i)] != type::PRIME)continue;
		result.first = pivot - i; result.second = N - (pivot - i);
		break;
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	init();
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		auto result = solution(n);
		cout << result.first << ' ' << result.second<<'\n';
	}
	return 0;
}