#include <iostream>
#include <string>
using namespace std;

string input;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int length = 0;
	while (!cin.eof()){
		cin >> input;
		if (input == "<br>") {
			length = 0;
			cout << '\n';
			continue;
		}
		else if (input == "<hr>") {
			if (length) { cout << '\n'; length = 0; }
			for (int t = 0; t < 80; ++t)cout << '-';
			cout << '\n';
			continue;
		}
		if (length) {
			if (length + input.size() + 1 <= 80) {
				length += 1;
				cout << " ";
			}
			else{
				length = 0;
				cout << '\n';
			}
		}
		length += input.size();
		cout << input;
	}
	return 0;
}