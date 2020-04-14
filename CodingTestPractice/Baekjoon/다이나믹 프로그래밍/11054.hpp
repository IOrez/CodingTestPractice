#include <iostream>

using namespace std;

int table[1000];
int ace_DP[1000];
int dec_DP[1000];

void Solution(int N)
{
	ace_DP[0] = 1;

	
	for (int i = 1; i < N; ++i)
	{
		int aceMaxVal = 0;
		for (int j = i - 1; j >= 0; --j)
			if (aceMaxVal<ace_DP[j] && table[i]>table[j])aceMaxVal = ace_DP[j];
		ace_DP[i] = aceMaxVal + 1;
	}

	dec_DP[N-1] = 1;
	for (int i = N-2; i >=0 ; --i)
	{
		int decMaxVal = 0;
		for (int j = i + 1; j <N; ++j)
			if (decMaxVal < dec_DP[j] && table[i] > table[j])decMaxVal = dec_DP[j];
		
		dec_DP[i] = decMaxVal + 1;
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
	{
		int aceMaxVal = -1;
		int decMaxVal = -1;
		for (int j = i ; j >= 0; --j)
			if (aceMaxVal < ace_DP[j])aceMaxVal = ace_DP[j];

		for (int j = i ; j < N; ++j)
			if (decMaxVal < dec_DP[j])decMaxVal = dec_DP[j];

		int sum = aceMaxVal + decMaxVal -1;
		if (max < sum)max = sum;
	}

	cout << max;

	return 0;
}