#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int a, b, v,sum = 0,cnt = 1;
	cin >> a >> b >> v;
	if(v>a)
	{
		v -= a;
		sum = a - b;
		cnt += v / sum;
		cnt += (bool)(v % sum);
	}
	cout << cnt;
	return 0;
}