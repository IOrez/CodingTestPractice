#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> v;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 2)cout << "NO" << endl;
		else
		{
			int sum = 0;
			for (int i = 0, even = 2; i < n / 2; ++i,even+=2)
			{
				v.push_back(even);
				sum += even;
			}

			for (int i = 0, odd = 1; i < n / 2 - 1; ++i, odd += 2)
			{
				v.push_back(odd);
				sum -= odd;
			}
			if (sum % 2 == 0)cout << "NO" << endl;
			else
			{
				cout << "YES" << endl;
				v.push_back(sum);
				for (auto i : v)
					cout << i << " ";
				cout << endl;
			}
			v.clear();
		}
	}

	return 0;
}