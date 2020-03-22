#include <cstdio>
#pragma warning(disable:4996)

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	int result = 0;

	while (n >= 2 * result&&result<=m)++result;
	if (n < 2 * result||m<result)--result;

	int remain = n + m - (3 * result);

	while (remain > 0&&k>0) { remain -= 1; k -= 1; }
	
	if (k > 0)
	{
		result -= k / 3;
		if (k % 3)result -= 1;
	}
	printf("%d", result<0?0:result);
	return 0;
}