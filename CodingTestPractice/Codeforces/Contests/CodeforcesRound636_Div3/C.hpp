#include <iostream>
#include <vector>
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
		vector<long long int> vec(n);
		for (int i = 0; i < n; ++i)
			cin >> vec[i];
		
		long long int sum = 0;
		long long int val = vec[0];
		for (int i = 1; i < n; ++i)
		{
			if (vec[i] * vec[i - 1] < 0)
			{
				sum += val;
				val = -9000000000;
			}
			if (val < vec[i])val = vec[i];
		}
		sum += val;
		cout << sum<<endl;
	}

	return 0;
}