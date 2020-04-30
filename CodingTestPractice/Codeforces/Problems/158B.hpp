#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;

	int sum = 0,cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	int fi = 0, ri = n - 1;
	while (fi < ri)
	{
		sum = v[ri--];
		while(sum + v[fi]<=4&&fi<=ri)
			sum += v[fi++];
		cnt++;
	}
	if (fi == ri)++cnt;
	cout << cnt;
	return 0;
}