#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;

int bs(int left, int right, vector<int>& v)
{
	if (left > right)
		return right;
	int mid = (left + right) / 2;
	int cnt = 0;
	for (int i = 0; i < v.size(); ++i)
		cnt += v[i] / mid;

	if (cnt < K)
		return bs(left, mid-1, v);
	else 
		return bs(mid+1, right, v);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K;
	vector<int> v(N);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	cout << bs(0, v[N - 1],v);

	return 0;
}