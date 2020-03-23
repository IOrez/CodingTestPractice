#include <cstdio>
#include <queue>

#pragma warning(disable:4996)

std::queue<unsigned long long> que;

int main()
{
	unsigned long long N;
	scanf("%llu", &N);
	unsigned long long result = 1;
	bool isFind = false;
	que.push(result);
	while (!que.empty())
	{
		result = que.front();
		
		que.pop();
		if (result % N == 0) {
			isFind = true; break;
		}
		unsigned long long pVal = result * 10;
		if(result<pVal)
			que.push(pVal);
		pVal += 1;
		if (result<pVal)
			que.push(pVal);
		
	}
	if (!isFind)printf("0\n");
	else printf("%llu", result);

	while (!que.empty())que.pop();
	return 0;
}