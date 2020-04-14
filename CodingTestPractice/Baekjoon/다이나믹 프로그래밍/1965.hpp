#include <iostream>

using namespace std;

int table[1000];
int DP[1000];

void Solution(int N)
{
	DP[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		int Max = 0;
		for (int j = i - 1; j >= 0; --j)
			if (Max<DP[j] && table[i]>table[j])Max = DP[j];
		DP[i] = Max + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> table[i];
	Solution(N);
	int max = -1;
	for (int i = 0; i < N; ++i)
		if (max < DP[i])max = DP[i];
	cout << max;
	return 0;
}