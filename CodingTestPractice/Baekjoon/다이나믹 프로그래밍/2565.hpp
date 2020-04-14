#include <iostream>

using namespace std;

int table[501];
int ace_DP[501];

void Solution(int N)
{
	for (int i = 1; i <= N; ++i)
	{
		if (table[i] == 0)continue;
		int aceMaxVal = 0;
		for (int j = i - 1; j >= 0; --j)
			if (aceMaxVal< ace_DP[j] && table[i]>table[j])aceMaxVal = ace_DP[j];
		ace_DP[i] = aceMaxVal + 1;
	
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0;i<N;++i)
	{
		int a, b;
		cin >> a >> b;
		table[a] = b;
	}
	Solution(500);
	int aceMaxVal = -1;
	for (int i = 1; i <= 500; ++i)
		if (aceMaxVal < ace_DP[i])aceMaxVal = ace_DP[i];

	
	cout << N - aceMaxVal;


	return 0;
}