#include <iostream>
#include <string>
#include <vector>
using namespace std;

unsigned long long Cnt;
unsigned long long DP[101][21];
int number,Val, N;
vector<int>input;
void solution()
{
	for (int i = 1; i < N - 1; ++i)
		for (int j = 0; j < 21; ++j)
		{
			Val = j + input[i];
			if (Val >= 0 && Val <= 20)
				DP[i][Val] += DP[i - 1][j];
			Val = j - input[i];
			if (Val >= 0 && Val <= 20)
				DP[i][Val] += DP[i - 1][j];
		}

	Cnt = DP[N-2][input[N - 1]];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> number;
		input.push_back(number);
	}
	
	DP[0][input[0]] = 1;
	solution();
	cout << Cnt;
	return 0;
}