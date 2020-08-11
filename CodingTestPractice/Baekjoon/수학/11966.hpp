#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	bool check = true;
	while (n != 1 && check)
	{
		if (n % 2 != 0)check = false;
		n /= 2;
	}
	cout << (bool)check;
	return 0;
}