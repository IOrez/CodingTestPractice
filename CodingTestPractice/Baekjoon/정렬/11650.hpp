#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int> > v(N);
	for (auto i = 0; i < N; ++i)
		cin >> v[i].first >> v[i].second;

	sort(begin(v), end(v));
	for (auto i : v)
		cout << i.first << " " << i.second << '\n';
	return 0;
}