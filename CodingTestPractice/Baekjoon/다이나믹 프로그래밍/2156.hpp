#include <iostream>

using namespace std;

int table[10000];
int DP[10000];

#define MAX(X,Y) (((X)>(Y)) ? (X):(Y))

void solution(int N)
{

	DP[0] = table[0];
	DP[1] = DP[0] + table[1];
	int val1 = table[0] + table[1];
	int val2 = table[0] + table[2];
	int val3 = table[1] + table[2];
	DP[2] = MAX(MAX(val1, val2), val3);

	for (int i = 3; i < N; ++i)
	{
		val1 = DP[i - 3] + table[i - 1] + table[i];
		val2 = DP[i - 2] + table[i];
		val3 = DP[i - 1];
		DP[i] = MAX(MAX(val1, val2), val3);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> table[i];

	solution(N);

	int max = -1;
	for (int i = 0; i < N; ++i)
		if (max < DP[i])max = DP[i];

	cout << max;

	return 0;
}