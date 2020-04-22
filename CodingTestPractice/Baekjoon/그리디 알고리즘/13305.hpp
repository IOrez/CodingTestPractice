#include <iostream>

using namespace std;

unsigned long long Distance[100001];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i < N; ++i)
		cin >> Distance[i];
	
	unsigned long long min = 1000000000;
	unsigned long long table = 0;
	unsigned long long result = 0;

	for (int i = 1; i <= N; ++i)
	{
		cin >> table;
		if (min > table)min = table;
		result += Distance[i] * min;
	}
	cout << result;
	return 0;
}