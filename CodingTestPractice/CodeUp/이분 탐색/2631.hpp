#include <iostream>
#include <deque>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int sum = 0;
	deque<int> deq;
	int val;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		if (val == K)
		{
			while (!deq.empty())deq.pop_front();
			sum = 0; cnt++;
		}
		else
		{
			if (val > K)
			{
				while (!deq.empty())deq.pop_front();
				sum = 0;
			}
			else
			{
				sum += val;
				deq.push_back(val);
				if (sum == K) cnt++;
				while (sum >= K && !deq.empty())
				{
					sum -= deq.front();
					if (sum == K)cnt++;
					deq.pop_front();
				}
			}
		}
	}

	cout << cnt;
	return 0;
}