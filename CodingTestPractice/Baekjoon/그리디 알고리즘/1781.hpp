#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int,int> Table[200001];
priority_queue<int> pq;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	int MaxDeadLine = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> Table[i].first >> Table[i].second;
	sort(Table, Table + N);
	for (int i = 0; i < N; ++i)
	{
		auto deadline = Table[i].first;
		auto cupnum = Table[i].second;
		pq.push(-cupnum);
		while (deadline < pq.size())
			pq.pop();

	}
	int sum = 0;
	while (!pq.empty())
	{
		sum += -pq.top();
		pq.pop();
	}
	cout << sum;
	return 0;
}