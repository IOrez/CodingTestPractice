#include <iostream>

using namespace std;
int table[100001];
int parent[100001];
int country[100001];

bool isSameParent(int a, int b,int* getRoot_a = nullptr,int* getRoot_b = nullptr)
{
	while (a != parent[a])
		a = parent[a];
	while (b != parent[b])
		b = parent[b];
	if (getRoot_a != nullptr)*getRoot_a = a;
	if (getRoot_b != nullptr)*getRoot_b = b;

	return a == b;
}

bool unionFind(int a, int b)
{
	int parent_a = 0, parent_b = 0;
	if (!isSameParent(a, b, &parent_a, &parent_b))
	{
		if (parent_a > parent_b)parent[parent_a] = parent_b;
		else parent[parent_b] = parent_a;
		return true;
	}
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N,M;
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; ++i)parent[i] = i;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		unionFind(a, b);
	}
	int C;
	cin >> C;
	while (C--)
	{
		int a, b;
		cin >> a >> b;
		while (a != parent[a])
			a = parent[a];
		country[a] = b;
	}

	for (int i = 1; i <= N; ++i)
	{
		int a=i;
		while (a != parent[a])
			a = parent[a];
		cout << country[a] << " ";
	}
	return 0;
}