#include <iostream>
#include <vector>
using namespace std;
int N;
using ull = unsigned long long;
ull D_treeCnt = 0, G_treeCnt = 0;
ull DP[300001][4];
ull D_tree(vector<vector<int>>& table,int vertex)
{
	int s = table[vertex].size();
	if (s-1 < 1)return 0;
	ull sum = 0;
	for (auto& i : table[vertex])
	{
		if (table[i].size() - 1 < 1)continue;
		sum += (s - 1) * (table[i].size() - 1);
	}
	return sum;
}

ull combi(int n, int r)
{
	if (n == r || r == 0)return 1;
	if (DP[n][r] != 0)return DP[n][r];
	DP[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
	return DP[n][r];
}
ull G_tree(vector<vector<int>>& table, int vertex)
{
	int s = table[vertex].size();
	if (s < 3)return 0;
	return combi(s,3);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<vector<int>> table(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int s, e;
		cin >> s >> e;
		table[s].push_back(e);
		table[e].push_back(s);
	}
	for (int i = 1; i <= N; ++i)
	{
		D_treeCnt += D_tree(table, i);
		G_treeCnt += G_tree(table, i);
	}
	D_treeCnt /= 2;
	if (D_treeCnt > G_treeCnt * 3)cout << 'D';
	else if (D_treeCnt < G_treeCnt * 3)cout << 'G';
	else cout << "DUDUDUNGA";
	return 0;
}