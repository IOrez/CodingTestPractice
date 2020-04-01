#include <cstdio>
#include <limits>
#pragma warning(disable:4996)

#define MAX_SIZE	26


unsigned long distance[MAX_SIZE];
unsigned long arr[MAX_SIZE][MAX_SIZE];
bool isCheck[MAX_SIZE];
void init(const int v,const int e)
{
	for (int i = 0; i < MAX_SIZE; ++i)
		for (int j = 0; j < MAX_SIZE; ++j)
		{
			arr[i][j] = std::numeric_limits<int>::max();
			if (i == j)arr[i][j] = 0;
		}
	
	for (int i = 0; i < e; ++i)
	{
		char startP, endP;
		int edgeVal;
		getchar();
		scanf("%c %c %d",&startP,&endP,&edgeVal);
		startP -= 'A';
		endP -= 'A';
		arr[(int)startP][(int)endP] = edgeVal;
		arr[(int)endP][(int)startP] = edgeVal;
	}
	getchar();
}

void dijkstra(int startP,const int num)
{
	isCheck[startP] = true;
	for (int i = 0; i < num; ++i)
		distance[i] = arr[startP][i];
	while (true)
	{
		int MinP = startP;
		int MinVal = std::numeric_limits<int>::max();
		for (int i = 0; i < num; ++i)
		{
			if (!isCheck[i] && MinVal > distance[i])
			{
				MinVal = distance[i];
				MinP = i;
			}
		}
		if (MinVal == std::numeric_limits<int>::max())break;
	
		isCheck[MinP] = true;
		for (int i = 0; i < num; ++i)
			distance[i] = (distance[i] < distance[MinP] + arr[MinP][i] ? distance[i]: distance[MinP] + arr[MinP][i]);
	}
}

int main()
{
	int v, e;
	scanf("%d%d", &v, &e);
	init(v,e);
	char startP, endP;
	scanf("%c %c", &startP, &endP);
	dijkstra(startP-'A',v);
	if (distance[endP - 'A'] == std::numeric_limits<int>::max())printf("-1");
	else printf("%d", distance[endP - 'A']);
}