#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int val; cin >> val;
		auto iter = lower_bound(v.begin(), v.end(), val);
		if (iter == v.end())cout << 0;
		else if (*iter != val)cout << 0;
		else cout << 1;
		cout << '\n';
	}


	return 0;
}