#include <iostream>
#include <vector>

using namespace std;

#define SIZE 101

int Table[SIZE][SIZE];
int N;
int xi, yi, w, h;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;	
	vector<int> results(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> xi >> yi >> w >> h;
		for (int y = yi; y < yi + h; ++y)
			for (int x = xi; x < xi + w; ++x)
				Table[y][x] = i;
	}

	for (int y = 0; y < SIZE; ++y)
		for (int x = 0; x < SIZE; ++x)
			results[Table[y][x]]++;


	for (int i = 1; i < results.size(); ++i)
		cout << results[i] << ' ';
	return 0;
}