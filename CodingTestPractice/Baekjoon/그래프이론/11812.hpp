#include <iostream>
#include <algorithm>
using namespace std;
long long N, K, Q;
int main()
{
	//P = (N-2)/K +1
	//(P: Parent Node/ N: Child Node/ K: Degree)

	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> K >> Q;
	long long sum = 0, level = -1;
	long long start, end;
	for (int i = 0; i < Q; ++i)
	{
		cin >> start >> end;
		if (K == 1)
			cout << abs(start - end) << '\n';
		else
		{
			int cnt = 0;
			while (true)
			{
				if (start == end)break;
				long long Max = max(start, end);
				if (Max == start)
					start = (Max - 2) / K + 1;
				else
					end = (Max - 2) / K + 1;
				cnt++;
			}
			cout << cnt<<'\n';
		}
	}
	return 0;
}