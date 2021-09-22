#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int N, M;
int table[50][50];

vector<pair<int, int>> houses;
vector<pair<int, int>> markets;
vector<bool> cases;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			if (table[i][j] == 1)
				houses.push_back({ i,j });
			else if (table[i][j] == 2) {
				markets.push_back({ i,j });
				cases.push_back(true);
				table[i][j] = 0;
			}
		}
	for (int i = 0; i < M; ++i)
		cases[i] = false;
	
	int totmindis = numeric_limits<int>::max();
	do{
		for (int i = 0; i < markets.size(); ++i)
			if(cases[i]==false)
				table[markets[i].first][markets[i].second] = 2;

		int sumdis = 0;
		for (int i = 0; i < houses.size(); ++i) {
			int mindis = numeric_limits<int>::max();
			for (int j = 0; j < markets.size(); ++j) {
				if (cases[j] != false)continue;

				int dis = abs(houses[i].first - markets[j].first) + abs(houses[i].second - markets[j].second);
				if (mindis > dis)
					mindis = dis;
			}
			sumdis += mindis;
		}

		if (totmindis > sumdis)totmindis = sumdis;

		for (int i = 0; i < markets.size(); ++i)
			if (cases[i] == false)
				table[markets[i].first][markets[i].second] = 0;

	}while (next_permutation(cases.begin(), cases.end()));
	
	cout << totmindis;

	return 0;
}