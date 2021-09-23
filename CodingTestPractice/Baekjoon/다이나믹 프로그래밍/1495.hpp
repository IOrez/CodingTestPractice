#include <iostream>
#include <algorithm>

using namespace std;
int N, M, S;

int V[101];
bool check[101][1001];


void solution(int idx,int volume) {
	if (idx > N)return;
	if (check[idx][volume])return;
	check[idx][volume] = true;

	if (volume + V[idx] <= M)solution(idx + 1, volume + V[idx]);
	if (volume - V[idx] >= 0)solution(idx + 1, volume - V[idx]);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> S >> M;
	for (int i = 0; i < N; ++i)
		cin >> V[i];

	solution(0, S);
	int maxVolume = -1;
	for (int i = 0; i <= M; ++i)
		if (check[N][i])maxVolume = i;

	cout << maxVolume;
	return 0;
}