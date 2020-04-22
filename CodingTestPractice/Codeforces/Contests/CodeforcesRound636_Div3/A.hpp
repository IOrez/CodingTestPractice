#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int k = 2;
		int result;
		for (;; ++k)
			if ((n % (int)(pow(2, k) - 1)) == 0) { result = n / (int)(pow(2, k) - 1); break; }

		cout << result<<endl;
	}
	return 0;
}