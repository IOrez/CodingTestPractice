#include <iostream>
using namespace std;

char c[8][8];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int cnt = 0;
	for (int i = 0; i < 8; ++i) {
		bool isWhite = i%2==0;
		for (int j = 0; j < 8; ++j) {
			cin >> c[i][j];
			if (isWhite && c[i][j] == 'F')cnt++;
			isWhite = !isWhite;
		}
		cin.ignore();
	}
	cout << cnt;
	return 0;
}