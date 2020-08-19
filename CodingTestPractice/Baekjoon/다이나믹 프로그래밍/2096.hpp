#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <functional>
using namespace std;
int N;
int Table[100000][3];

int solution(bool isMin) {
	
	int DP[2][3] = { 0,0,0,0,0,0 };
	function<int(initializer_list<int>)> func = [&](initializer_list<int> list) {return max(list);};
	if (isMin)
		func = [&](initializer_list<int> list) {return min(list);};
	for (int j = 0; j < 3; ++j)DP[0][j] = Table[0][j];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			DP[1][j] = DP[0][j] + Table[i][j];
			switch (j) {
			case 0:
				DP[1][j] = func({ DP[1][j],DP[0][j + 1] + Table[i][j] }); break;
			case 1:
				DP[1][j] = func({ DP[1][j],DP[0][j - 1] + Table[i][j] });
				DP[1][j] = func({ DP[1][j],DP[0][j + 1] + Table[i][j] }); break;
			case 2:
				DP[1][j] = func({ DP[1][j],DP[0][j - 1] + Table[i][j] }); break;
			}
		}
		for (int j = 0; j < 3; ++j)DP[0][j] = DP[1][j];
	}
	return func({ DP[0][0],DP[0][1] ,DP[0][2] });
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> Table[i][j];

	cout << solution(false) << " " << solution(true);

	return 0;
}