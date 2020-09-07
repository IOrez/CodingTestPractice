#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	cin >> input;
	for (int i = 0, cnt = 0; i < input.size(); ++i, ++cnt) {
		if (cnt == 10) { cnt = 0; cout << '\n'; }
		cout << input[i];
	}
	return 0;
}