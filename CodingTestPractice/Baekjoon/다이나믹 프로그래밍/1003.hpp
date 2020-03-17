#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)

#define MAX_BUFFER_SIZE 41

typedef struct PAIR
{
	int m_Count0{};
	int m_Count1{};

	friend PAIR operator +(PAIR& obj1, PAIR& obj2);

}PAIR;

PAIR pair[MAX_BUFFER_SIZE];

PAIR operator+(PAIR& obj1, PAIR& obj2)
{
	PAIR result{ obj1.m_Count0 + obj2.m_Count0,obj1.m_Count1 + obj2.m_Count1 };
	return result;
}

void init()
{
	pair[0] = PAIR{ 1,0 };
	pair[1] = PAIR{ 0,1 };
	for (int i = 2; i < MAX_BUFFER_SIZE; ++i)
		pair[i] = pair[i - 1] + pair[i - 2];
}

int main()
{
	init();
	int test,n;
	scanf("%d", &test);
	for (auto i = 0; i < test; ++i)
	{
		scanf("%d", &n);
		printf("%d %d\n", pair[n].m_Count0, pair[n].m_Count1);
	}
	return 0;
}