#include <cstdio>
#include <cstring>
#pragma warning(disable:4996)

#define MAX_BUFFER_SIZE	51

char A[MAX_BUFFER_SIZE]="";
char B[MAX_BUFFER_SIZE]="";

int main()
{
	scanf("%s %s", A, B);
	int aLen = strlen(A);
	int bLen = strlen(B);

	int dif = bLen - aLen;
	int minCount = 9999999, count;
	for (int i = 0; i <= dif; ++i)
	{
		count = 0;
		for (int idx = i; idx < i+ aLen; ++idx)
			if (A[idx-i] != B[idx])count++;
		
		if (minCount > count)minCount = count;
	}
	printf("%d", minCount);

	return 0;
}