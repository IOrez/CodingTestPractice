#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)

std::pair<int,int> step[301];
int score[301];
int main()
{
	int n;
	scanf("%d", &n);
	for (auto i = 1; i <= n; ++i)
		scanf("%d", &score[i]);
	step[0] = { score[0],score[0] };
	step[1] = { score[1],score[1] };
	
	for (int i = 2; i <= n; ++i)
	{
		int a = score[i] + (step[i - 2].first>step[i-2].second? step[i - 2].first: step[i - 2].second);
		int b = score[i] + step[i - 1].first;
		step[i] = { a,b };
	}
	printf("%d\n", step[n].first>step[n].second? step[n].first: step[n].second);
	return 0;
}