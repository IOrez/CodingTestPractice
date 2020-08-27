#include <iostream>

using namespace std;
int N;

bool DP[1001];
void sol() {
	int i = 0;
	while (i < N) {
		if (i + 3 <= N){
			DP[i + 3] = !DP[i];
			i += 3;
		}
		else {
			DP[i + 1] = !DP[i];
			i += 1;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	sol();
	if (DP[N])
		cout << "SK";
	else
		cout << "CY";
	return 0;
}