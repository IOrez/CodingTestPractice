#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N, M;
string input;
int table[10][10];

int FindPower(int value) {
	int result = -1;
	int i = (int)sqrt(value);
	if (i * i == value)result = value;

	return result;
}

bool IsInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

void Solution() {
	int result = -1;
	if (N == 1 && M == 1)
		result = FindPower(table[0][0]);
	else {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				for (int nstep = -N + 1; nstep < N; ++nstep) {
					for (int cstep = -M + 1; cstep < M; ++cstep) {
						if (cstep == 0 && nstep == 0)continue;
						int value = 0, r = i, c = j;
						
						while (IsInRange(r, c)) {
							value *= 10; value += table[r][c];
							result = max(result, FindPower(value));
							r += nstep; c += cstep;
						}
					}
				}
			}
		}
	}
	cout << result << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M; cin.ignore();
	for (int i = 0; i < N; ++i) {
		getline(cin, input);
		for (int j = 0; j < M; ++j)
			table[i][j] = input[j] - '0';
	}
		
	Solution();

	return 0;
}