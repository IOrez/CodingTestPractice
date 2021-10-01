#include <iostream>
#include <string>
using namespace std;
int t;
string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> input;
		int result = 0;
		int cnt = 0;
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] == 'O')result += (++cnt);
			else if (input[i] == 'X')cnt = 0;
		}
		cout << result << '\n';
	}
	return 0;
}