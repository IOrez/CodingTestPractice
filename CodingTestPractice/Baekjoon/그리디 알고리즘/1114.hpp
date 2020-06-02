#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;


priority_queue<pair<long long, long long>> pq;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int L, K, C;
	int pos = INT_MAX;
	cin >> L >> K >> C;
	vector<float> point(K);
	for (auto& i : point)cin >> i;
	sort(point.begin(), point.end());
	pq.push({ L,0 });
	while (C--)
	{
		auto Length = pq.top().first;
		auto sPoint = pq.top().second;
		auto ePoint = sPoint + Length;
		float val = (float)(sPoint + ePoint) / 2;
		auto iter = lower_bound(point.begin(), point.end(),val );
		if (iter == point.end())
		{
			iter--;
			if (*iter == sPoint) {
				C++; pq.pop(); continue;
			}
		}
		else if (iter == point.begin())
		{
			if (*iter == ePoint){
				C++; pq.pop(); continue;
			}
		}
		else
		{
			bool bStart = *(iter - 1) == sPoint;
			bool bEnd = *iter == ePoint;
			if (bStart && bEnd){
				C++; pq.pop(); continue;
			}
			else if (bStart || bEnd)
			{
				if (bEnd)iter--;
			}
			else
			{
				int n1 = abs(*(iter - 1) - val);
				int n2 = abs(*iter - val);
				if (n1 <= n2)iter = iter - 1;
			}
		}
		pq.pop();
		if (pos > *iter)pos = *iter;
		pq.push({ *iter - sPoint,sPoint });
		pq.push({ ePoint - *iter,*iter });
	}
	cout << pq.top().first << " " << pos << '\n';
}