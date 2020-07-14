#include <iostream>
#include <vector>
using namespace std;


enum Color
{
	UNKNOWN,BLACK,WHITE
};

Color c[20001];
bool  check[20001];


bool solution(vector<vector<int>>& v, int sVertex)
{
	bool result = true;
	for (auto i = (size_t)0; i < v[sVertex].size() && result; ++i)
		if (c[v[sVertex][i]] == UNKNOWN)c[v[sVertex][i]] = (Color)(3 - c[sVertex]);
		else result = (c[v[sVertex][i]] == (Color)(3 - c[sVertex]));

	if (result)
		for (auto i = (size_t)0; i < v[sVertex].size() && result; ++i)
		{
			if (check[v[sVertex][i]])continue;
			check[v[sVertex][i]] = true;
			result = solution(v, v[sVertex][i]);
		}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		int V, E;
		cin >> V >> E;
		for (int i = 1; i <= V; ++i)
		{
			c[i] = UNKNOWN;
			check[i] = false;
		}
		vector<vector<int> > table(V+1);
		for (int i = 0; i < E; ++i)
		{
			int start, end;
			cin >> start >> end;
			table[start].push_back(end);
			table[end].push_back(start);
		} 
		bool result = true;
		for (int i = 1; i <= V && result; ++i)
		{
			if (check[i])continue;
			c[i] = BLACK;
			check[i] = true;
			result = solution(table, i);
		}
		if (result)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}