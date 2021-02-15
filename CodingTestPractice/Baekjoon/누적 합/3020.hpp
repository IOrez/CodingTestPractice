#include <iostream>

using namespace std;

#define SIZE 500001

int N, H,Min,Min_line;
int table[2][SIZE];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> H;
	int h;
	for (int i = 0; i < N; ++i) {
		cin >> h;
		table[i % 2][h]++;
	}

	for (int i = 0; i < 2; ++i)
		for (int j = H - 1; j > 0; --j)
			table[i][j] += table[i][j + 1];

	Min = N + 1;
	for (int i = 1; i <= H; ++i) {
		int t_sum = table[0][i] + table[1][H + 1 - i];
		if (Min > t_sum) {
			Min = t_sum;
			Min_line = 1;
		}
		else if (Min == t_sum)
			Min_line++;
	}
	cout << Min <<" "<<Min_line;
	return 0;
}