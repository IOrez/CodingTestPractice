#include <cstdio>
#pragma warning(disable:4996)

int greedy(int start, int end)
{
	int s = start <= end ? start : end;
	int e = start <= end ? end : start;

	int i = e - s;
	int t_v = 0; int f_v = 0;
	int count = 0;
	t_v = i / 10;
	if (i % 10 > 7)t_v += 1;
	i -= 10 * t_v;
	count += t_v;
	if (i < 0)i *= -1;
	f_v = i / 5;
	if (i % 5 > 2)f_v+=1;
	i -= 5 * f_v;
	if (i < 0)i *= -1;
	count += f_v;
	count += i;
	return count;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int result = greedy(a, b);
	printf("%d", result);
	return 0;
}