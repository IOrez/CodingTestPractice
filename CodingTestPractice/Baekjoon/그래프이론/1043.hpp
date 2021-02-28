#include <iostream>
#include <vector>

using namespace std;

using vp = vector<pair<bool, vector<int>>>;

vp party, v;
vector<int> t;
int N, M, T, num, who;

void searchAttendees(int idx);

void searchParty(int idx){
	auto& [check,attendees] = party[idx];
	if (check)return;
	check = true;

	for (int i = 0; i < attendees.size(); ++i)
		searchAttendees(attendees[i]);
}

void searchAttendees(int idx) {
	auto& [check, attendat] = v[idx];
	if (check)return;
	check = true;

	for (int i = 0; i < attendat.size(); ++i)
		searchParty(attendat[i]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N >> M;
	v.resize(N+1);
	party.resize(M);
	
	cin >> T;
	t.resize(T);
	for (auto& i : t)
		cin >> i;

	for (int i = 0; i < M; ++i) {
		cin >> num;
		for (int j = 0; j < num; ++j) {
			cin >> who;
			v[who].second.push_back(i);
			party[i].second.push_back(who);
		}
	}
	for (auto& i : t)
		searchAttendees(i);


	int ans = 0;
	for (int i = 0; i < party.size(); ++i)
		if (!party[i].first)ans++;

	cout << ans;
	return 0;
}