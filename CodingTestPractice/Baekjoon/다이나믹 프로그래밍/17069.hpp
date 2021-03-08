#include <iostream>

using namespace std;

int table[32][32];
long long DP[32][32][3];

int N;

bool isInRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

long long solution(int y,int x,int t) {
	if (y == N - 1 && x == N - 1)return 1;
	long long res = 0;
	switch (t) {
	case 0:
		if (isInRange(y, x + 1)&&!table[y][x+1]) {
			if (DP[y][x + 1][0]>0)res += DP[y][x + 1][0];
			else if(DP[y][x + 1][0]==0)res += solution(y, x + 1, 0);
		}

		if (isInRange(y + 1, x + 1)&& !table[y+1][x + 1]&&
			isInRange(y, x + 1) && !table[y][x + 1]&&
			isInRange(y + 1, x) && !table[y + 1][x]) {
			if (DP[y + 1][x + 1][2]>0)res += DP[y + 1][x + 1][2];
			else if(DP[y + 1][x + 1][2] ==0)res += solution(y + 1, x + 1, 2);
		}

		break;
	case 1:
		if (isInRange(y + 1, x)&& !table[y + 1][x]) {
			if (DP[y + 1][x][1]>0)res += DP[y + 1][x][1];
			else if(DP[y + 1][x][1] == 0)res += solution(y + 1, x, 1);
		}

		if (isInRange(y + 1, x + 1) && !table[y + 1][x + 1] &&
			isInRange(y, x + 1) && !table[y][x + 1] &&
			isInRange(y + 1, x) && !table[y + 1][x]) {
			if (DP[y + 1][x + 1][2] > 0)res += DP[y + 1][x + 1][2];
			else if (DP[y + 1][x + 1][2] == 0)res += solution(y + 1, x + 1, 2);
		}
		break;
	case 2:
		if (isInRange(y, x + 1) && !table[y][x + 1]) {
			if (DP[y][x + 1][0] > 0)res += DP[y][x + 1][0];
			else if (DP[y][x + 1][0] == 0)res += solution(y, x + 1, 0);
		}
		if (isInRange(y + 1, x) && !table[y + 1][x]) {
			if (DP[y + 1][x][1] > 0)res += DP[y + 1][x][1];
			else if (DP[y + 1][x][1] == 0)res += solution(y + 1, x, 1);
		}
		if (isInRange(y + 1, x + 1) && !table[y + 1][x + 1] &&
			isInRange(y, x + 1) && !table[y][x + 1] &&
			isInRange(y + 1, x) && !table[y + 1][x]) {
			if (DP[y + 1][x + 1][2] > 0)res += DP[y + 1][x + 1][2];
			else if (DP[y + 1][x + 1][2] == 0)res += solution(y + 1, x + 1, 2);
		}
		break;
	}
	if (res == 0) {
		DP[y][x][t] = -1;
		return 0;
	}
	DP[y][x][t] = res;
	return DP[y][x][t];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];

	long long ans = solution(0, 1, 0);

	cout << ans;

	return 0;
}