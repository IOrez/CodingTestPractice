#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE	20
int N;
int Table[SIZE][SIZE];

int solution() {
	int Min = numeric_limits<int>::max();
	vector<int> mask;
	for (int i = 0; i < N / 2; ++i)mask.push_back(0);
	for (int i = 0; i < N / 2; ++i)mask.push_back(1);
	do {
		int AteamStat = 0, BteamStat = 0;
		vector<int> Ateam,Bteam;
		for (int i = 0; i < mask.size(); ++i)
			if (mask[i])Ateam.push_back(i);
			else Bteam.push_back(i);

		for (int i = 0; i < Ateam.size(); ++i)
			for (int j = 0; j < Ateam.size(); ++j)
				AteamStat += Table[Ateam[i]][Ateam[j]];

		for (int i = 0; i < Bteam.size(); ++i)
			for (int j = 0; j < Bteam.size(); ++j)
				BteamStat += Table[Bteam[i]][Bteam[j]];

		Min = min(Min, abs(AteamStat - BteamStat));

	} while (next_permutation(mask.begin(), mask.end()));

	return Min;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for(int i =0 ;i<N;++i)
		for (int j = 0; j < N; ++j)
			cin >> Table[i][j];

	cout << solution();
	return 0;
}