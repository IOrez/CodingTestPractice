#include <iostream>
#include <vector>
#include <algorithm>

#define INF 999999999

using namespace std;

int			  table[100];
bool		  used[100];
int           concent[100];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K, plugCount = 0, concentIdx = 0;
	cin >> N >> K;
	for (auto i = 0; i < K; ++i)
	{
		cin >> table[i];
		--table[i];
	}

	for (int i = 0; i < K; ++i)
	{
		if (used[table[i]])continue;
		else if (concentIdx < N)
		{
			concent[concentIdx++] = table[i];
			used[table[i]] = true;
			continue;
		}
		
		plugCount++;
		int maxVal = 0;
		int idx = 0;
		for (int j = 0; j < N; ++j)
		{
			int distance = INF;
			for (int k = i + 1; k < K; ++k)
			{
				if (concent[j] == table[k])
				{
					distance = k;
					break;
				}
			}
			if (distance > maxVal)
			{
				idx = j;
				maxVal = distance;
			}
		}
		used[concent[idx]] = false;
		used[table[i]] = true;
		concent[idx] = table[i];
	}
	
	cout << plugCount;
	return 0;
}