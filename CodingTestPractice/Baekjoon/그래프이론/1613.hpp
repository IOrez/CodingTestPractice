#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N,K,S,p1,p2;

int table[401][401];
void Floyd() {
	for (int k = 1; k <= N; ++k) 
		for (int i = 1; i <= N; ++i) 
			for (int j = 1; j <= N; ++j) 
				if (table[i][k]&&table[k][j]) {
					table[i][j] = 1;
				}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		cin >> p1 >> p2;
		table[p1][p2] = 1;
	}
	Floyd();
	cin >> S;
	for (int i = 0; i < S; ++i) {
		cin >> p1 >> p2;
		if (table[p1][p2] == 0 && table[p2][p1] == 0)
			cout << 0 << '\n';
		else {
			if (table[p1][p2])
				cout << -1 << '\n';
			else
				cout << 1 << '\n';
		}
	}

	return 0;
}