#include <iostream>

using namespace std;

int table[101];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int number;
		cin >> number;
		table[number] = i;
	}
	for (int i = 1; i <= N; ++i)
		cout << table[i] << " ";
	return 0;
}