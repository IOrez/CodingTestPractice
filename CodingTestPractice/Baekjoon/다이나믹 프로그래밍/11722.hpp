#include <iostream>
#include <algorithm>
using namespace std;
int N;
int DP[1000], Table[1000];
void solution()
{
	for (int i = 0; i < N; ++i)
	{
		int Max = DP[i];
		for (int j = i - 1; j >= 0; --j)
			if (Max < DP[j] && Table[j] > Table[i])Max = DP[j];
		DP[i] = Max + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Table[i];
	solution();
	cout << *std::max_element(DP, DP + N);
	return 0;
}