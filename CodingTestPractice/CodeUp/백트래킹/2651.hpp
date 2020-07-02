#include <iostream>

using namespace std;
int n, k, cnt;
void solution(int num,int idx)
{
	if (num == k)cnt++;
	else
		for (int i = idx ; i <= n; ++i)
		{
			if (n - i + 1 < k - num)break;
			solution(num + 1, i+1);
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	solution(0, 1);
	cout << cnt;
	return 0;
}