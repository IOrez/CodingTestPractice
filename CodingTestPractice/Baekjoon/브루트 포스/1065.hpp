#include <iostream>

using namespace std;

int cnt;

void solution(int n)
{
	bool check = true;
	int temp = n;
	int m, d, dif;
	m = temp % 10;
	d = (temp / 10) % 10;
	dif = m - d;
	while (temp / 10!=0)
	{
		m = temp % 10;
		d = (temp / 10) % 10;
		if (dif != m - d) { check = false; break; }
		temp /= 10;
	}
	if (check)cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		solution(i);
	cout << cnt;
	return 0;
}