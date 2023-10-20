#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v;
int N;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	int num;
	int val = 0;
	priority_queue<int> min_pq, max_pq;
	vector<int> ans;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (i == 0)
		{
			val = num;
		}
		else
		{
			if (val > num)
				max_pq.push(num);
			else
				min_pq.push(-num);

			int minSize = min_pq.size();
			int maxSize = max_pq.size();
			if (minSize - maxSize >= 2)
			{
				max_pq.push(val);
				val = -min_pq.top();
				min_pq.pop();
			}
			else if (maxSize - minSize >= 1)
			{
				min_pq.push(-val);
				val = max_pq.top();
				max_pq.pop();
			}
		}

		ans.push_back(val);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}