#include <iostream>

using namespace std;

int N;

void solution(int n) {
	for (int i = 2; i <= n;) {
		if (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
		else
			i++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	if (N != 1) 
		solution(N);
	return 0;

}