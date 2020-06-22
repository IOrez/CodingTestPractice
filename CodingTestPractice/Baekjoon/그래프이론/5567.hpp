#include <iostream>
#include <vector>
using namespace std;

bool check[501];
int cnt;
vector<int> adj[501];

void solution(int v,int depth)
{
	if (depth==2)return;
	for (auto& i : adj[v])
	{
		if (!check[i])cnt++;
		check[i] = true;
		solution(i,depth+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n,m,start,end;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end;
		adj[start].push_back(end);
		adj[end].push_back(start);
	}
	int v = 1;
	check[v] = true;
	solution(v,0);
	cout << cnt;
	return 0;
}