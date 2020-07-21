#include <iostream>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int N, K;
		cin >> N >> K;
		int sum = 0;
		while (N--)
		{
			int num;
			cin >> num;
			sum += num / K;
		}
		cout << sum << '\n';
	}
	return 0;
}