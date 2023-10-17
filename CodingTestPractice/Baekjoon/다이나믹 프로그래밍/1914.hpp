#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#pragma warning (disable:4996)

long long DP[101];
char buf[128];
int K;
void Solution(int n, int start, int end, int middle)
{
	if (n <= 0)
		return;

	Solution(n - 1,start,middle,end);
	cout << start << " " << end << '\n';
	Solution(n - 1,middle, end, start);

	return;
}

int main()
{
	cin >> K;

	int N = K;
	unsigned long long preCnt = 0, cnt = 0;
	while (N--)
	{
		preCnt *= 2;
		cnt = 2 * cnt + 1;
		preCnt += cnt / 1000000000000000000;
		cnt %= 1000000000000000000;
	}
	
	if (preCnt != 0)
	{
		cout << preCnt << setw(18) << setfill('0') << cnt << '\n';
	}
	else
	{
		cout << cnt << '\n';
	}

	if (K <= 20)
		Solution(K, 1, 3, 2);
	

	return 0;
}