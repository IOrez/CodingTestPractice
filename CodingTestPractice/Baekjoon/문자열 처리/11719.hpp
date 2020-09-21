#include <iostream>
#include <string>
using namespace std;
string input;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	while (getline(cin, input)) {
		cout << input<<'\n';
	}

	return 0;
}