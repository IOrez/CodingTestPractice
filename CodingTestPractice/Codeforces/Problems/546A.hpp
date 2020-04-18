#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k, n, w;
	cin >> k >> n >> w;
	int cost = 0;
	for (int i = 1; i <= w; ++i)
		cost += i * k;

	int result = cost - n;
	if (result < 0)result = 0;

	cout << result;
	return 0;
}