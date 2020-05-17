#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,M,K;
	cin >> N >> M >> K;
	vector<int> v(N);
	if (K + M - 1 > N || N > M * K)
	{
		cout << "-1" << endl;
	}
	else
	{
		int C = N;
		int start = 1;
		while (true)
		{
			M--;
			C -= K;
			if (M == 0) {
				for (int i = N; i >= start; --i)
					cout << i << " ";
				break;
			}
			else if(C/M==0||C<0)
			{
				for (int i = start + K - 1 - (M - C); i >= start; --i)
					cout << i << " ";
				for (int i = start + K - (M - C); i <= N; ++i)
					cout << i << " ";
				break;
			}
			else
			{
				for (int i = start + K - 1; i >= start; --i)
					cout << i << " ";
				start += K;
			}
		}
	}
	return 0;
}