#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	unsigned int package = -1;
	unsigned int single = -1;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a < package)package = a;
		if (b < single)single = b;
	}
	
	int money = 0;
	if (6 * single < package)money = N * single;
	else
	{
		money += (N / 6) * package;
		N %= 6;
		if (N * single > package)money += package;
		else money += N * single;
	}

	cout << money;

	return 0;
}