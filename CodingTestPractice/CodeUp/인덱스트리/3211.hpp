#include <iostream>
#include <algorithm>
using namespace std;

#define INF  999999999

typedef struct pa
{
	int Max;
	int Min;
}PA;
PA table[200001];

int main()
{
	for (int i = 1; i <= 100001; ++i)
	{
		table[i].Max = -INF;
		table[i].Min = INF;
	}
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, s = 1,k = 0;
	cin >> n >> m;
	while (s < n) { k++; s *= 2; }
	for (int i = s; i < s + n; ++i)
	{
		cin >> table[i].Max;
		table[i].Min = table[i].Max;

		int pi = i / 2;
		int ci = i;
		while (pi != 0)
		{
			table[pi].Max = max({ table[pi].Max,table[ci].Max });
			table[pi].Min = min({ table[pi].Min,table[ci].Min });
			ci = pi;
			pi /= 2;
		}
	}

	while (m--)
	{
		int si, ei;
		cin >> si >> ei;
		si += s - 1; ei += s - 1;
		PA Lval = table[si];
		PA Rval = table[ei];
		while (si + 1 < ei)
		{
			if (si % 2 == 0)
			{
				Lval.Max = max({ Lval.Max,table[si + 1].Max });
				Lval.Min = min({ Lval.Min,table[si + 1].Min });
			}
			if (ei % 2 == 1)
			{
				Rval.Max = max({ Rval.Max,table[ei - 1].Max });
				Rval.Min = min({ Rval.Min,table[ei - 1].Min });
			}
			si /= 2;
			ei /= 2;
		}
		cout << max({ Lval.Max,Rval.Max }) - min({ Lval.Min,Rval.Min }) << '\n';
	}
	return 0;
}