#include <iostream>

using namespace std;

int DP[1001];
int Table[1001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,num;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> num;
		Table[i] = num;
		DP[i] = num;
	}

	for (int i = 2; i <= N; ++i)
		for (int j = i - 1; j > 0; --j)
			if (Table[j]<Table[i] && DP[j] + Table[i]>DP[i])
				DP[i] = DP[j] + Table[i];


	int idx = -1,Max = 0;
	for(int i =1;i<=N;++i)
		if (DP[i] > Max)
		{
			idx = i;
			Max = DP[i];
		}
	
	cout << Max;

	return 0;
}