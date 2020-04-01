#include <cstdio>
#include <vector>
#pragma warning(disable: 4996)

using namespace std;

vector<int> ans[1007];
int res[1007];

int main()
{
	auto f = [&](int u) {
		for (int i = 2; i <= u; ++i)
			if (u % i == 0)return i;
	};

	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i <= 1000; ++i)ans[i].clear();
		for (int i = 1; i <= n; ++i)
		{
			int u;
			scanf("%d", &u); ans[f(u)].push_back(i);
		}
		int ret = 0;
		for (int i = 1; i <= 1000; ++i)
		{
			if (ans[i].size())
			{
				++ret;
				for (auto c : ans[i])
					res[c] = ret;
			}
		}
		printf("%d\n", ret);
		for (int i = 1; i <= n; ++i)
			printf("%d ", res[i]);
		printf("\n");
	}
	return 0;
}