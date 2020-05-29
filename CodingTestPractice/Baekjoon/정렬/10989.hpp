#include <iostream>
using namespace std;

#define SIZE 10001

int table[SIZE];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		table[a]++;
	}
	
	for (int i = 1; i < SIZE; ++i)
	{
		while (table[i]--)
			cout << i << '\n';
	}

	return 0;
}