#include <iostream>
using namespace std;

int main() {
	int N;
	int Sum = 0;
	cin >> N; cin.ignore();
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;
		Sum += c - '0';
	}
	cout << Sum;
}