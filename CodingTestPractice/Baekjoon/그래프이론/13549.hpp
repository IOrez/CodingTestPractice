#include <iostream>
#include <queue>
using namespace std;

#define MAX_CHECK_POINTS 100001

int N, K;
int check[MAX_CHECK_POINTS];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	priority_queue<pair<int, int>> pq;
	
	for (int i = 0; i < MAX_CHECK_POINTS; i++)
		check[i] = MAX_CHECK_POINTS;

	cin >> N >> K;
	pq.push(make_pair(0, N));
	check[N] = 0;

	int ans = -1;
	while (!pq.empty())
	{
		auto [step, point] = pq.top();
		pq.pop();
		step *= -1;

		if (point == K)
		{
			ans = step;
			break;
		}

		if (K > point)
		{
			if (2 * point < MAX_CHECK_POINTS && check[2 * point] > step)
			{
				pq.push(make_pair(-(step), 2 * point));
				check[2 * point] = step;
			}

			if (point + 1 < MAX_CHECK_POINTS && check[point + 1] > step + 1)
			{
				pq.push(make_pair(-(step + 1), point + 1));
				check[point + 1] = step + 1;
			}
		}

		if (0 < point && check[point - 1] > step + 1)
		{
			pq.push(make_pair(-(step + 1), point - 1));
			check[point - 1] = step + 1;
		}
	}

	cout << ans;

	return 0;
}