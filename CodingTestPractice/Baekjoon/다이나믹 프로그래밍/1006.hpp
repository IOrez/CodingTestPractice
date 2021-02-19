#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;
const int SIZE = 10001;
int N, W, T;

int Table[2][SIZE];
int A[SIZE],B[SIZE],C[SIZE],result;

void solution(int start) {
	for (int i = start; i < N; ++i) {
		A[i+1] = min({ B[i],C[i] }) + 1;
		if (Table[0][i] + Table[1][i] <= W)
			A[i + 1] = min({ A[i + 1],A[i] + 1 });
		if (i > 0 && Table[0][i - 1] + Table[0][i] <= W && Table[1][i - 1] + Table[1][i] <= W)
			A[i + 1] = min({ A[i + 1],A[i - 1] + 2 });
		if (i < N-1) {
			B[i + 1] = A[i + 1] + 1;
			C[i + 1] = A[i + 1] + 1;
			if (Table[0][i] + Table[0][i+1] <= W)
				B[i + 1] = min({ B[i + 1],C[i] + 1 });
			if (Table[1][i] + Table[1][i+1] <= W)
				C[i + 1] = min({ C[i + 1],B[i] + 1 });
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> N >> W;
		result = numeric_limits<int>::max();
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < N; ++j)
				cin >> Table[i][j];
	
		B[0] = C[0] = 1;
		solution(0);
		result = min(result, A[N]);

		if (N>1&&Table[0][0] + Table[0][N - 1] <= W) {
			A[1] = 1;
			B[1] = 2;
			C[1] = Table[1][0] + Table[1][1] <= W ? 1 : 2;
			solution(1);
			result = min(result, C[N - 1] + 1);
		}

		if (N > 1 && Table[1][0] + Table[1][N - 1] <= W) {
			A[1] = 1;
			B[1] = Table[0][0] + Table[0][1] <= W ? 1 : 2;
			C[1] = 2;
			solution(1);
			result = min(result, B[N - 1] + 1);
		}

		if (N > 1 && Table[1][0] + Table[1][N - 1] <= W&& Table[0][0] + Table[0][N-1] <= W) {
			A[1] = 0;
			B[1] = 1;
			C[1] = 1;
			solution(1);
			result = min(result, A[N - 1] + 2);
		}

		cout << result << '\n';
	}
	return 0;
}