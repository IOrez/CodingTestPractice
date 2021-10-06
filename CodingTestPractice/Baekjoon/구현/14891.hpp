#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string input[4];
int Sawtooth[4][8];
bool check[4];
int M, A, B;


void Change(int idx,int dir) {
	if (dir == -1) {
		int tmp = Sawtooth[idx][0];
		for (int i = 0; i < 7; ++i)Sawtooth[idx][i] = Sawtooth[idx][i + 1];
		Sawtooth[idx][7] = tmp;
	}
	else if (dir == 1) {
		int tmp = Sawtooth[idx][7];
		for (int i = 7; i > 0; --i)Sawtooth[idx][i] = Sawtooth[idx][i - 1];
		Sawtooth[idx][0] = tmp;
	}
}

void Solution(int idx,int dir) {
	if (check[idx])return;
	check[idx] = true;
	int ndir = dir * -1;
	if (idx == 0) {
		bool Rres = (Sawtooth[idx][2] != Sawtooth[idx + 1][6]);
		if(Rres)
			Solution(idx + 1, ndir);
	}
	else if (idx == 3) {
		bool Lres = (Sawtooth[idx][6] != Sawtooth[idx - 1][2]);
		if (Lres)
			Solution(idx - 1, ndir);
	}
	else {
		bool Rres = (Sawtooth[idx][2] != Sawtooth[idx + 1][6]);
		bool Lres = (Sawtooth[idx][6] != Sawtooth[idx - 1][2]);
		if (Rres)
			Solution(idx + 1, ndir);
		if (Lres)
			Solution(idx - 1, ndir);
	}
	Change(idx, dir);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	for (int i = 0; i < 4; ++i) {
		getline(cin, input[i]);
		for (int j = 0; j < 8; ++j)Sawtooth[i][j] = (input[i][j] - '0');
	}

	cin >> M;
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		memset(check, false, sizeof(check));
		cin >> A >> B;
		A -= 1;
		Solution(A, B);
	}
	ans = Sawtooth[0][0] * 1 + Sawtooth[1][0] * 2 + Sawtooth[2][0] * 4 + Sawtooth[3][0] * 8;
	cout << ans << '\n';

	return 0;
}