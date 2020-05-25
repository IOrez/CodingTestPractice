#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

using tiii = tuple<int, int, int>;


int Max = 1;
int table[500][500];
int DP[500][500];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,1,-1 };

bool isInRange(int r, int c, int n)
{
	return 0 <= r && r < n && 0 <= c && c < n;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	cin >> N;
	vector<tuple<int, int, int>> v;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			cin >> table[i][j];
			v.push_back({ table[i][j],i,j });
			DP[i][j] = 1;
		}

	sort(v.begin(), v.end(), [&](tiii& obj1, tiii& obj2)
	{
		auto& [val_obj1, r_obj1, c_obj1] = obj1;
		auto& [val_obj2, r_obj2, c_obj2] = obj2;
		if (val_obj1 < val_obj2)return true;
		else return false;
	});

	for (int pivot = 0; pivot < N * N; ++pivot)
	{
		auto& [val, r, c] = v[pivot];
		for (int i = 0; i < 4; ++i)
		{
			int n_r = r + dr[i], n_c = c + dc[i];
			if (!isInRange(n_r, n_c, N))continue;
			if (table[n_r][n_c] > table[r][c] && DP[n_r][n_c] < DP[r][c] + 1)
			{
				DP[n_r][n_c] = DP[r][c] + 1;
				if (DP[n_r][n_c] > Max)Max = DP[n_r][n_c];
			}
		}
	}
	cout << Max;
	return 0;
}