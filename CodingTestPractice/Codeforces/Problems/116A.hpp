#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int max = 0;
	int capacity = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		capacity -= a;
		capacity += b;
		if (max < capacity)max = capacity;
	}
	cout << max;

	return 0;
}