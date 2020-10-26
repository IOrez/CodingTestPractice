#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int DP[10001][20];
int test,N,Num;

void solution(vector<int>& v) {
	for (int i = 0; i < N; ++i)DP[v[i]][i] = 1;
	for (int i = 1; i <= Num; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i - v[j] < 0)continue;
			for(int k =0;k<=j;++k)
			DP[i][j] += DP[i - v[j]][k];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> test;
	while (test--) {
		memset(DP, 0, sizeof(DP));
		cin >> N;
		vector<int> v(N);
		for (auto& i : v)
			cin >> i;
		cin >> Num;
		solution(v);
		int Sum = 0;
		for (int i = 0; i < N; ++i)
			Sum += DP[Num][i];
		cout << Sum << '\n';
	}
	return 0;
}