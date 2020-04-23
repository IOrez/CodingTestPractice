#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)cin >> v[i];
	sort(v.begin(), v.end());

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sum + 1 - v[i] < 0)break;
		sum += v[i];
	}
	cout << sum + 1;
	return 0;
}