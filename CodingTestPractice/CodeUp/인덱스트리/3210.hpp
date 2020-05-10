#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,m,a,b;
	cin >> n;
	int k = 0;
	int space = 1;
	while (space < n) { k++; space *= 2; }
	int Size = (int)pow(2, k + 1);
	vector<int> v(Size);
	for (int i = space; i < space+n; ++i)
	{
		cin >> v[i];
		int pi = i / 2;
		int ci = i;
		while (pi)
		{
			v[pi] = v[pi] > v[ci] ? v[pi] : v[ci];
			ci = pi;
			pi /= 2;
		}
	}
	
	cin >> m;
	while (m--)
	{
		cin >> a >> b;
		a += space-1; b += space-1;
		int LVal = v[a];
		int RVal = v[b];
		while (a+1 < b)
		{
			if (a % 2 == 0)LVal = LVal > v[a + 1] ? LVal : v[a + 1];
			if (b % 2 == 1)RVal = RVal > v[b - 1] ? RVal : v[b - 1];
			a /= 2;
			b /= 2;
		}
		int result = LVal > RVal ? LVal:RVal;
		cout << result << " ";
	}
	return 0;
}