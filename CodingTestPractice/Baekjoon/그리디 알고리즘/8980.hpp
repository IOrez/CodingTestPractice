#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> Table[2001];
int Truck[2001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, C, M;
	int startV, endV, boxNum;
	int contain = 0;
	int boxCnt = 0;
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> startV >> endV >> boxNum;
		if (startV >= endV)continue;
		Table[startV].push_back({ endV,boxNum });
	}
	for (int i = 1; i <= N; ++i)
		sort(Table[i].begin(), Table[i].end());

	endV = 0;
	for (int i = 1; i < N; ++i)
	{
		contain -= Truck[i];
		Truck[i] = 0;
		for (auto info : Table[i])
		{
			if (contain + info.second > C)
			{
				int dif = info.second - (C - contain);
				while (endV > info.first&&dif>0)
				{
					if (dif - Truck[endV] <= 0)
					{
						Truck[endV] -= dif;
						boxCnt -= dif;
						contain -= dif;
						dif = 0;
					}
					else
					{
						dif -= Truck[endV];
						boxCnt -= Truck[endV];
						contain -= Truck[endV];
						Truck[endV] = 0;
						endV--;
					}
				}
				Truck[info.first] += info.second - dif;
				boxCnt += info.second - dif;
				contain += info.second - dif;
			}
			else
			{
				Truck[info.first] += info.second;
				boxCnt += info.second;
				contain += info.second;
			}
			if (info.first > endV)endV = info.first;
		}
	}
	cout << boxCnt;
	return 0;
}