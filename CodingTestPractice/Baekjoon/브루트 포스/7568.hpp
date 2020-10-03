#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vtable;
int N, W, T;

void solution() {
	for (int i = 0; i < N; ++i) {
		int rank = 1;
		for (int j = 0; j < N; ++j) {
			if (i == j)continue;
			if (vtable[i].first < vtable[j].first &&
				vtable[i].second < vtable[j].second)
				rank++;
		}
		cout << rank << " ";
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> W >> T;
		vtable.push_back({ W,T });
	}
	solution();
	return 0;
}