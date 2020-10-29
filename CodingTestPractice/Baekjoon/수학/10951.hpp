#include <iostream>
#include <string>
using namespace std;
string input;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	while (!getline(cin, input).eof()) {
		cout << (input[0] - '0') + (input[2] - '0') << '\n';
	}
	return 0;
}