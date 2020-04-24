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
	vector<int> sort_v(N);
	for (int i = 0; i < N; ++i) { cin >> v[i]; sort_v[i] = v[i]; }
	sort(sort_v.begin(), sort_v.end());

	for (int i = 0; i < N; ++i)
	{
		auto iter = lower_bound(sort_v.begin(), sort_v.end(), v[i]);
		cout << iter - sort_v.begin() <<" ";
	}
	return 0;
}