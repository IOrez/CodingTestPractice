#include <cstdio>
#include <limits>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

template <typename T,typename... Types>
int FindMin(Types... args)
{
	std::vector<T> v = { args... };
	return *std::min_element(std::begin(v), std::end(v));
}

int A[1000001];
void func(int A[],int idx)
{
	bool isDivBy3 = false, isDivBy2=false;
	if (idx%3==0) isDivBy3 = true;
	if (idx%2==0) isDivBy2 = true;
	if (isDivBy2 && isDivBy3)
		A[idx] = FindMin<int>(A[idx / 3], A[idx / 2], A[idx - 1])+1;
	else
	{
		if (isDivBy2)
			A[idx] = FindMin<int>(A[idx / 2], A[idx - 1]) + 1;
		else if (isDivBy3)
			A[idx] = FindMin<int>(A[idx / 3],A[idx - 1]) + 1;
		else
			A[idx] = A[idx-1] + 1;
	}
}
void init()
{
	A[1] = 0; A[2] = 1; A[3] = 1;
	for (int i = 4; i < 1000001; ++i)
		func(A, i);
}
int main()
{
	init();

	int i;
	scanf("%d", &i);
	printf("%d", A[i]);
	return 0;
}