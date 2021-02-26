#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int table[50][50];
int R1, C1, R2, C2;
int boundY, boundX, maxDigit;

bool isInRange(int y, int x) {
	return R1 <= y && y <= R2 && C1 <= x && x <= C2;
}

void saveTable(int y, int x, int num) {
	table[y - R1][x - C1] = num;

	int tmp = num, digit = 0;

	while (tmp != 0) {
		digit++;
		tmp /= 10;
	}

	maxDigit = max(maxDigit, digit);
}


void solution() {
	int y = 0, x = 0;
	int num = 1, step = 0;
	if (isInRange(y, x))
		saveTable(y, x, num);
	num++;
	while (abs(y) <= boundY || abs(x) <= boundX) {
		x += 1;
		step += 2;
		for (int i = 0; i < step; ++i,++num) {
			if (isInRange(y-i, x))
				saveTable(y-i, x, num);
		}
		y -= (step - 1);
		x -= 1;
		for (int i = 0; i < step; ++i,++num) {
			if (isInRange(y, x-i))
				saveTable(y, x-i, num);
		}
		x -= (step - 1);
		y += 1;
		for (int i = 0; i < step; ++i,++num) {
			if (isInRange(y+i, x))
				saveTable(y+i, x, num);
		}
		y += (step - 1);
		x += 1;
		for (int i = 0; i < step; ++i,++num) {
			if (isInRange(y, x+i))
				saveTable(y, x+i, num);
		}
		x += (step - 1);
	}
}
int main() {
	cin >> R1 >> C1 >> R2 >> C2;
	boundY = max(abs(R1), abs(R2));
	boundX = max(abs(C1), abs(C2));

	solution();
	for (int i = R1; i <= R2; ++i) {
		for (int j = C1; j <= C2; ++j)
			cout << setw(maxDigit)<<table[i - R1][j - C1] << " ";
		cout << '\n';
	}
}