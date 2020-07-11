#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int groupCnt[3001];
int parent[3001];

typedef struct Line
{
	pair<int, int> p1;
	pair<int, int> p2;
}Line;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int op = a.first * b.second +b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}

int getParent(int a)
{
	int tmp = a;
	while (tmp != parent[tmp])tmp = parent[tmp];
	return tmp;
}

void unionFind(int a, int b)
{
	int& pa = parent[getParent(a)];
	int& pb = parent[getParent(b)];
	if (pa != pb)
	{
		if (pa < pb)
		{
			groupCnt[pa] += groupCnt[pb];
			groupCnt[pb] = 0;
			pb = pa;
		}
		else
		{
			groupCnt[pb] += groupCnt[pa];
			groupCnt[pa] = 0;
			pa = pb;
		}
	}
}

bool isIntersect(Line l1, Line l2)
{
	pair<int, int> a = l1.p1;
	pair<int, int> b = l1.p2;
	pair<int, int> c = l2.p1;
	pair<int, int> d = l2.p2;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0)
	{
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	Line l;
	cin >> N;
	vector<Line> v(N + 1);
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	
	for(int i = 1;i<=N;++i)
	{
		cin >> l.p1.first >> l.p1.second >> l.p2.first >> l.p2.second;
		v[i] = l;
		groupCnt[i] = 1;
		for (int j = 1; j < i; ++j)
		{
			if (isIntersect(v[j], l))
				unionFind(j, i);
		}
	}
	int Max = -1;
	int gCnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (groupCnt[i] > 0)gCnt++;
		if (groupCnt[i] > Max)
			Max = groupCnt[i];
	}
	cout << gCnt << '\n' << Max << '\n';
	return 0;
}