#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int A, B;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> A >> B;

	priority_queue<pair<long long, long long>> pq;
	pq.push(make_pair(-A, 0));

	int answer = -1;

	while (!pq.empty())
	{
		auto [number, count] = pq.top();
		pq.pop();
		number *= -1;
		if (number == B)
		{
			answer = count + 1;
			break;
		}

		if (number * 2 <= B)
		{
			pq.push(make_pair(-number * 2, count + 1));
		}

		if (number * 10 + 1 <= B)
		{
			pq.push(make_pair(-(number * 10 + 1), count + 1));
		}
	}

	cout << answer;
}