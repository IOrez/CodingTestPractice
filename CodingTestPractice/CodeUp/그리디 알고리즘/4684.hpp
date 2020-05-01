#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	int k1 = 0, k2 = 0, p = 0, q = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)cin >> i;
	
	int reverseCnt = 0;
	for (int i = 0; i < n; ++i)
		if ((v[(i + 1) % n] - v[i] + n)%n == 1)reverseCnt++;

	reverseCnt = n - reverseCnt - 1;

	if (reverseCnt == n-1)
	{
		k1 = v[n - 1]%n;
		p = q = 0;
		k2 = 0;
	}
	else if (reverseCnt == -1)
	{
		k1 = 0;
		p = 0;
		q = n - 1;
		k2 = v[0] % n;
	}
	else
	{
		int k = 0;
		bool reverseFlag = false;
		while (1)
		{
			if ((v[(k + 1) % n] - v[k % n] + n) % n != 1)reverseFlag = true;
			else
			{
				if (reverseFlag)
				{
					q = (k - 1) % n;
					break;
				}
			}
			k++;
		}
		p = (q - reverseCnt + n +1) % n;
		k2 = n - p;
		k1 = v[q] - 1;
		p = 0;
		q = reverseCnt - 1;
	}
	cout << k1 << "\n";
	cout << p + 1 << " " << q+1 << "\n";
	cout << k2;
	return 0;
}

/*
	1 10 3 4 5 6 7 8 9 2
	2 1 10 3 4 5 6 7 8 9	....(1)
	10 1 2 3 4 5 6 7 8 9    ....(1,3)
	1 2 3 4 5 6 7 8 9 10    ....(9)

	10 1 2 3 4 5 6 7 8 9
	2 1 10 3 4 5 6 7 8 9
	9 2 1 10 3 4 5 6 7 8

	5 4 3 2 1 10 9 8 6 7
	8 9 10 1 2 3 4 5 6 7
	1 2 3 4 5 6 7 8 9 10

	3 2 1 10 9 8 7 6 5 4
*/