#include <cstdio>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef struct set
{
	int pack_val=0;
	int single_bal=0;
}SET;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<SET >v(m);
	int min_val = 99999;
	for (int i = 0; i < m; ++i)
	{
		int pack_val; int single_val;
		scanf("%d %d", &pack_val, &single_val);
		if (single_val * 6 < pack_val)pack_val = single_val * 6;
		if (min_val > single_val)min_val = single_val;
		v[i] = { pack_val,single_val };
	}
	sort(begin(v), end(v), [&](const SET& obj1, const SET& obj2)->bool{
		
		if (obj1.pack_val == obj2.pack_val)
			return obj1.single_bal <obj2.single_bal;

		return obj1.pack_val <obj2.pack_val;
	});
	int i = 0;
	int cost = 0;
	while (n > 0)
	{
		if (n - 6 >= 0)
		{
			cost += v[i].pack_val;
			n -= 6;
		}
		else
		{
			if (n * min_val > v[i].pack_val) { cost += v[i].pack_val; n -= 6; }
			else cost += min_val;
			n -= 1;
		}
	}
	printf("%d\n", cost);
	return 0;
}