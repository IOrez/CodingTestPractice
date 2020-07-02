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
	int pos = INT_MAX, maxLength = -1;
	cin >> L >> K >> C;
	vector<float> point(K+2);
	point[0] = 0;
	point[K + 1] = L;
	for (int i = 1; i <= K; ++i)cin >> point[i];
	sort(point.begin(), point.end());
	pq.push({ L,0 });
	while (C--)
	{
		auto Length = pq.top().first;
		auto sPoint = -pq.top().second;
		auto ePoint = sPoint + Length;
		pq.pop();
		float val = (float)(sPoint + ePoint) / 2;
		auto iter = lower_bound(point.begin(), point.end(),val );
		if (ePoint == *iter) 
		{
			C++;
			if (maxLength < Length)maxLength = Length;
		}
		else
		{
			int p1 = *(iter - 1);
			int p2 = *iter;
			int cutPoint = p2;
			if (p1 != *point.begin())
			{
				int dis1 = abs((p1 - sPoint) - (ePoint - p1));
				int dis2 = abs((p2 - sPoint) - (ePoint - p2));
				if (dis1 <= dis2)
					cutPoint = p1;
			}
			pq.push({ cutPoint - sPoint,-cutPoint }); 
			pq.push({ ePoint - cutPoint ,-cutPoint });
			if (pos > cutPoint)pos = cutPoint;
		}
	}
	if (maxLength < pq.top().first)maxLength = pq.top().first;
	cout << maxLength << " " << pos << '\n';

}