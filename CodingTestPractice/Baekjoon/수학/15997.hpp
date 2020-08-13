#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;
map<string,int> team;
vector<tuple<int, int, float, float, float>> table;
vector<int>score(4);
vector<pair<int, int>>r(4);
float per[4];
void solution(int i,float p){
	if (i == 6) {
		for (int i = 0; i < 4; ++i){
			r[i].first = score[i];
			r[i].second = i;
		}
		sort(r.begin(), r.end(),greater<pair<int,int>>());
		int S[4], id[4];
		for (int i = 0; i < 4; ++i){
			S[i] = r[i].first;
			id[i] = r[i].second;
		}
		if (S[1] != S[2]) {
			per[id[0]] += p; per[id[1]] += p;
		}
		else if (S[0] == S[1] && S[2] == S[3]) {
			per[id[0]] += p/2; per[id[1]] += p/2;
			per[id[2]] += p/2; per[id[3]] += p/2;
		}
		else if (S[2] == S[3]) {
			per[id[0]] += p;
			per[id[1]] += p / 3; per[id[2]] += p / 3; per[id[3]] += p / 3;
		}
		else if (S[0] == S[1]) {
			per[id[0]] += p * 2.0 / 3; per[id[1]] += p * 2.0 / 3; per[id[2]] += p * 2.0 / 3;
		}
		else {
			per[id[0]] += p;
			per[id[1]] += p / 2; per[id[2]] += p / 2;
		}
		return;
	}
	auto& [t1, t2, w, d, l] = table[i];
	score[t1] += 3;
	solution(i + 1, p * w);
	score[t1] -= 3;

	score[t1] += 1; score[t2] += 1;
	solution(i + 1, p * d);
	score[t1] -= 1; score[t2] -= 1;

	score[t2] += 3;
	solution(i + 1, p * l);
	score[t2] -= 3;

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	for (int i = 0; i < 4; ++i) {
		cin >> input;
		team[input] = i;
	}
	for (int i = 0; i < 6; ++i) {
		string team1, team2;
		float w, d, l;
		cin >> team1 >> team2;
		cin >> w >> d >> l; cin.ignore();
		table.push_back(make_tuple(team[team1], team[team2], w, d, l));
	}
	solution(0, 1.0f);

	for (int i = 0; i < 4; ++i)
		cout << fixed << setprecision(6)<<per[i] << '\n';

	return 0;
}