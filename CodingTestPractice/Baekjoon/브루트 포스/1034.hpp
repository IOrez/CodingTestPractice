#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 50

using namespace std;
int N, M, K;
int Max;

string table[SIZE];

void solution() {
	for (int y = 0; y < N; ++y) {
		int res = 0, cnt = 0;
		for (int x = 0; x < M; ++x)
			if (table[y][x] == '0')cnt++;

		if (cnt > K||(K-cnt)%2)continue;

		for (int i = y; i < N; ++i)
			if (table[y] == table[i])res++;

		Max	 = max(Max, res);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M; cin.ignore();
	for (int i = 0; i < N; ++i)
		getline(cin, table[i]);

	cin >> K;
	solution();
	cout << Max;
	return 0;

}