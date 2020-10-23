#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t,A, B;
	cin >> t;
	int i = t;
	while (t--) {
		cin >> A >> B;
		cout << "Case #" << i - t <<": "<< A + B << '\n';
	}

	return 0;
}