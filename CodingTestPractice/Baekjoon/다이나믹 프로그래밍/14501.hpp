#include <iostream>
using namespace std;

int table_t[16];
int table_p[16];
int DP[16];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> table_t[i] >> table_p[i];
		if (table_t[i] + i > N + 1)table_p[i] = 0;
	}

	for (int i =N; i >= 1; --i)
	{
		int max = 0;
		for (int j = i + table_t[i]; j <= N; ++j)
			max = max > DP[j] ? max : DP[j];
		
		DP[i] = max + table_p[i];
	}
	int max = 0;
	for(int i = 1;i<=N;++i)
		max = max > DP[i] ? max : DP[i];
	cout << max;
	return 0;
}