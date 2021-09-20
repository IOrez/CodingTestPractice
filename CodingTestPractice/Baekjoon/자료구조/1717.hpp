#include <iostream>
#include <vector>
using namespace std;

int n, m;

int FindParent(vector<int>& table, int a) {
	if (table[a] == a)return a;
	return table[a] = FindParent(table, table[a]);
}

void UnionFind(int t,vector<int>& table,int a,int b) {
	int tmp_a = FindParent(table, a), tmp_b = FindParent(table, b);
	switch (t)
	{
	case 0:
		if (tmp_a < tmp_b)table[tmp_b] = tmp_a;
		else table[tmp_a] = tmp_b;
		break;
	case 1:
		if (tmp_a == tmp_b)cout << "YES" << '\n';
		else cout << "NO" << '\n';
		break;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	vector<int> table(n+1);
	
	for (int i = 0; i < table.size(); ++i)
		table[i] = i;

	int t, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> t >> a >> b;
		UnionFind(t, table, a, b);
	}
	return 0;
}