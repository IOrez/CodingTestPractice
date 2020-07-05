#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int L, K, C, Max, R;
int table[10002];

void sol(int s, int e,int c)
{
	if (s > e||c>=C)return;
	int mid = (s + e) / 2;
	int dif = 0, i = K;
	bool check = true;
	int sMax = -1;
	for (; i >= 1; --i)
	{
		dif += table[i + 1] - table[i];
		if (dif > table[K + 1] - mid)
		{
			check = false;
			break;
		}
		sMax = max({ sMax,table[K+1] - table[i] });
	}
	i += 1;
	if (check)
	{
		sMax = max({ sMax,table[i] - table[0] });
		if (sMax <= Max && R>table[i])
		{
			Max = sMax;
			R = table[i];
		}
		sol(mid + 1, e,c+1);
	}
	else sol(0, mid - 1,c);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> L >> K >> C;
	Max = INT_MAX, R = INT_MAX;
	table[0] = 0; table[K + 1] = L;
	sort(table, table + K + 1);
	for (int i = 1; i <= K; ++i)cin >> table[i];
	sol(0, L,0);
	cout << Max << " " << R << '\n';
	return 0;
}