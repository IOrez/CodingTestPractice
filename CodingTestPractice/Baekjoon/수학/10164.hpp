#include <iostream>

using namespace std;

#define SIZE 15

using ull = unsigned long long;
ull Table[SIZE][SIZE];
int N, M, K;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < SIZE; ++i) { Table[i][0] = 1; Table[0][i] = 1; }
	for (int y = 1; y < SIZE; ++y)
		for (int x = 1; x < SIZE; ++x)
			Table[y][x] = Table[y - 1][x] + Table[y][x - 1];

	cin >> N >> M >> K;
	if (K == 0)
		cout << Table[N - 1][M - 1];
	else {
		int Y = (K - 1) / M, X = (K - 1) % M;
		cout << Table[Y][X] * Table[N - 1 - Y][M - 1 - X];
	}
	return 0;
}