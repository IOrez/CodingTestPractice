#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;

int main()
{
	int a, b;
	while (scanf("%d %d",&a,&b) > 0)
	{
		if (pq.size() == 15)
		{
			int w = -pq.top().first;
		}
		else
			pq.push({ -(a + b),{a,b} });
	}
	
	return 0;
}