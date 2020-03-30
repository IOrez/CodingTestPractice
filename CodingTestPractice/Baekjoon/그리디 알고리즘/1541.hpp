#include <cstdio>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_BUFFER_SIZE 51
char seq[MAX_BUFFER_SIZE] = "";

int main()
{
	scanf("%s", seq);
	int len = strlen(seq);
	int sign = 1;
	int result = 0;
	int num = 0;
	int sum = 0;
	for (auto i = 0; i < len; ++i)
	{
		if (seq[i] == '-') {
			sum += num;
			num = 0;
			result += sign * sum;
			sum = 0;
			sign = -1;
		}
		else if (seq[i] == '+')
		{
			sum += num;
			num = 0;
		}
		else
		{
			num *= 10;
			num += seq[i] - '0';
		}
	}
	sum += num;
	result += sign * sum;

	printf("%d", result);
	return 0;
}