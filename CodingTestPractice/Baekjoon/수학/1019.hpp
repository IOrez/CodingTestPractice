#include <iostream>
#include <vector>
using namespace std;

vector<int> ans(10);
int digit = 1;

void calc(int N) {
	while (N > 0) {
		ans[N % 10] += digit;
		N /= 10;
	}
}

void solution(int S,int N) {

	while (S <= N) {
		while (N % 10 != 9 && S <= N)
			calc(N--);
		while (S % 10 != 0 && S <= N)
			calc(S++);

		if (N < S)break;

		S /= 10;
		N /= 10;

		for (int i = 0; i < 10; ++i)
			ans[i] += (N - S + 1) * digit;

		digit *= 10;
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	solution(1,N);
	for (auto& i : ans)
		cout << i << ' ';
	return 0;
}