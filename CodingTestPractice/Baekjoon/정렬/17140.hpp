#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int A[100][100];
int Count[101];
int r, c, k;
int maxR = 3, maxC = 3;

void Sort() {
	if (maxR >= maxC) {
		for (int r = 0; r < maxR; ++r) {
			priority_queue<pair<int, int>> pq;
			memset(Count, 0, sizeof(Count));
			for (int c = 0; c < maxC; ++c)
				Count[A[r][c]]++;
			for (int i = 1; i <= 100; ++i)
				if (Count[i] != 0)pq.push({ -Count[i],-i });
			
			int c = 0;
			while (!pq.empty() && c < 100) {
				auto [preq, value] = pq.top();
				pq.pop();
				A[r][c] = -value; A[r][c + 1] = -preq;
				c += 2;
				if (maxC < c)maxC = c;
			}
			while (c < maxC)
				A[r][c++] = 0;
		}
	}
	else {
		for (int c = 0; c < maxC; ++c) {
			priority_queue<pair<int, int>> pq;
			memset(Count, 0, sizeof(Count));
			for (int r = 0; r < maxR; ++r)
				Count[A[r][c]]++;
			for (int i = 1; i <= 100; ++i)
				if (Count[i] != 0)pq.push({ -Count[i],-i });

			int r = 0;
			while (!pq.empty() && r < 100) {
				auto [preq, value] = pq.top();
				pq.pop();
				A[r][c] = -value; A[r + 1][c] = -preq;
				r += 2;
				if (maxR < r)maxR = r;
			}
			while (r < maxR)
				A[r++][c] = 0;
		}
	}
}

int solution() {
	int i = 0;
	for (; i <= 100; ++i) {
		if (r < maxR && c < maxC && A[r][c] == k)break;
		Sort();
	}
	return (i <= 100) ? i : -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> r >> c >> k;
	r -= 1;
	c -= 1;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> A[i][j];
	
	cout << solution();
	return 0;
}