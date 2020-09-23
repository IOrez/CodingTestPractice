#include <iostream>

using namespace std;

int num, cnt;
int main() {
	cin >> num;
	int k = num;
	do {
		int a = num % 10;
		int b = num / 10;
		num = a * 10 + (a + b) % 10;
		cnt++;
	} while (k != num);
	
	cout << cnt;

	return 0;
}