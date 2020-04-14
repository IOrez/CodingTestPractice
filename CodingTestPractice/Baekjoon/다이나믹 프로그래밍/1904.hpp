#include <iostream>

using namespace std;

int DP[1000001];

#define MOD 15746

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	DP[1] = 1;
	DP[2] = 2;
	int N;
	cin >> N;
	for (int i = 3; i <= N; ++i)
		DP[i] = (DP[i - 1]%MOD + DP[i - 2]%MOD)%MOD;
	cout << DP[N];
	return 0;
}