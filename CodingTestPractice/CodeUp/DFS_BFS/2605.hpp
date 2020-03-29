#include <cstdio>
#include <stack>
#pragma warning(disable:4996)

#define MAX_SIZE	7

using namespace std;

int		plane[MAX_SIZE][MAX_SIZE];
bool	isCheck[MAX_SIZE][MAX_SIZE];

enum class COLOR
{
	RED = 1,YELLOW,BLUE,GREEN,PURPLE
};

int dfs(stack<pair<int, int>>& st,int& count)
{
	int isSeq = 0;
	pair<int,int> p = st.top();
	int x = p.second;
	int y = p.first;
	isCheck[y][x] = true;
	COLOR color = (COLOR)plane[y][x];
	int dx[4] = { -1, 1, 0,  0 };
	int dy[4] = { 0, 0, 1, -1 };
	for (auto t = 0; t < 4; ++t)
	{
		int gx = x + dx[t];
		int gy = y + dy[t];
		if (gy < 0 || gy>6 || gx < 0 || gx>6)continue;
		if (isCheck[gy][gx])continue;
		if (color == (COLOR)plane[gy][gx])
		{
			st.push({ gy,gx });
			count += 1;
			int r_val = dfs(st,count);
			isSeq = count >= 2 ? 1 : 0;
		}
	}
	st.pop();
	
	return isSeq;
}

int main()
{
	for (auto y = 0; y < MAX_SIZE; ++y)
		for (auto x = 0; x < MAX_SIZE; ++x)
			scanf("%d", &plane[y][x]);
	int sum = 0;
	stack<pair<int, int>> st;

	for (auto y = 0; y < MAX_SIZE; ++y)
		for (auto x = 0; x < MAX_SIZE; ++x)
		{
			if (!isCheck[y][x])
			{
				int count = 0;
				st.push({ y,x });
				sum += dfs(st,count);
			}
		}

	printf("%d", sum);
	return 0;
}