#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unsigned long long S;
	cin >> S;
	unsigned long long cnt = 0;
	unsigned long long n = 0;
	unsigned long long sum = 0;
	while (sum < S)
	{
		sum += ++n;
		cnt++;
	}
	if (sum > S)cnt--;
	cout << cnt;
	return 0;
}
