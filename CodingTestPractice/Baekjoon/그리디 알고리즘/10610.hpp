#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

#define MAX_BUFFER_SIZE	100001

char cArr[MAX_BUFFER_SIZE] = "";
int main()
{
	scanf("%s", cArr);
	const size_t size = strlen(cArr);
	std::vector<char> nArr(size);
	int sum = 0;
	int index = 0;
	bool has0 = false;
	while (cArr[index] != '\0')
	{
		int val = cArr[index] - '0';
		if (val == 0 && !has0)has0 = true;
		sum += val;
		nArr[index] = val;
		index++;
	}

	if (!has0 || sum % 3 != 0)printf("-1\n");
	else {
		std::sort(std::begin(nArr), std::end(nArr), [&](int a, int b)->bool {return a > b; });
		for (auto i = std::begin(nArr); i != std::end(nArr); ++i)
			printf("%d", *i);
		printf("\n");
	}

	return 0;
}