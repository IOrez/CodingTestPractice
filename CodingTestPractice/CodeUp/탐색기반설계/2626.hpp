#include <iostream>
#include <cmath>

using namespace std;

int solution(int N) 
{
	int longest = ceill((double)N / 3);
	int cnt = 0;
	while (true)
	{
		int rest = N - longest;
		if (rest <= longest)break;
		for (int i = 1; i <= rest; ++i)
		{
			if (rest - i > longest)continue;
			if (i > rest - i)break;
			cnt++;
		}
		longest++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	cout << solution(n);
	return 0;
}