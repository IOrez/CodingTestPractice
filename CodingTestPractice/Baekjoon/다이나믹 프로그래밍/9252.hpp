#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define SIZE 1001

string input[2];
string ans;

int DP[SIZE][SIZE];

int LCS(int a_idx, int b_idx) {
	if (a_idx <= 0 || b_idx <= 0) return 0;
		int& ret = DP[a_idx][b_idx];
	if (ret != -1)return ret;

	if (input[0][a_idx-1] == input[1][b_idx-1])
		ret = LCS(a_idx - 1, b_idx - 1) + 1;
	else
		ret = max(LCS(a_idx - 1, b_idx), LCS(a_idx, b_idx - 1));

	return ret;
}

void LongestStr(int a_idx, int b_idx) {
	if (a_idx <= 0 || b_idx <= 0) return;
	if (input[0][a_idx-1] == input[1][b_idx-1]) {
		ans += input[0][a_idx-1];
		LongestStr(a_idx - 1, b_idx - 1);
	}
	else {
		if (DP[a_idx - 1][b_idx] > DP[a_idx][b_idx - 1])
			LongestStr(a_idx - 1, b_idx);
		else
			LongestStr(a_idx, b_idx - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < 2; ++i)
		getline(cin, input[i]);

	int maxLength = LCS(input[0].size(), input[1].size());
	cout << maxLength<<'\n';
	if (maxLength != 0) {
		LongestStr(input[0].size(), input[1].size());
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	return 0;
}