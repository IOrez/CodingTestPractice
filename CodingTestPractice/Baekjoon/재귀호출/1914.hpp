#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int n;
void hanoi(int start, int temp, int end,int num)
{
	if (num <= 0)return;
	hanoi(start, end, temp, num - 1);
	cout << start << " " << end << '\n';
	hanoi(temp, start, end, num - 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int num = n;
	unsigned long long preCnt = 0 , cnt = 0;
	while (n--)
	{
		preCnt *= 2;
		cnt = 2 * cnt + 1;
		preCnt += cnt / 1000000000000000000;
		cnt = cnt % 1000000000000000000;
	}
	if(preCnt!=0)
		cout << preCnt <<setw(18)<<setfill('0')<<cnt<<'\n';
	else
		cout << cnt << '\n';
	if (num <= 20)
		hanoi(1, 2, 3, num);	
	return 0;
}