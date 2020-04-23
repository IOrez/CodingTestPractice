#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int, int >> v(N);
	priority_queue<int> que;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first;
		cin >> v[i].second;
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int max = v[0].second;
	for (int i = 1; i < N; ++i)
	{
		que.push(-v[i].second);
		if (max <= v[i].first) { max = -que.top(); que.pop(); }
		else { cnt++; que.push(-max); max = -que.top(); que.pop(); }
	}
	cout << cnt;
	return 0;
}