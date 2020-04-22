#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int isCheck[20001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		memset(isCheck, 0, sizeof(isCheck));
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		
		int max = -1;
		for (int i = 0; i < n / 2; ++i)
		{
			int x = v[i] + v[n - 1 - i];
			isCheck[x]++;
			if (max < isCheck[x])max = isCheck[x];
		}
		
		cout << n / 2 - max << endl;
	}
	return 0;
}