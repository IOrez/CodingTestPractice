#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;


const int SIZE =  'z' - 'a' + 1;

int N, K, cnt = 5, Max;
string input;
vector<bitset<SIZE>> v;
bitset<SIZE> alpha;

void solution(int idx) {
	if (cnt == K) {
		int ans = 0;
		for (int i = 0; i < v.size(); ++i)
			if ((alpha.to_ulong() & v[i].to_ulong()) == v[i].to_ulong())ans++;
		Max = max(Max, ans);
		return;
	}
	for (int i = idx; i < SIZE; ++i) {
		if (alpha[i])continue;
		alpha[i] = 1; cnt++;
		solution(i + 1);
		alpha[i] = 0; cnt--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K; cin.ignore();

	alpha['a' - 'a'] = 1;
	alpha['n' - 'a'] = 1;
	alpha['t' - 'a'] = 1;
	alpha['c' - 'a'] = 1;
	alpha['i' - 'a'] = 1;


	for (int i = 0; i < N; ++i) {
		getline(cin, input);
		bitset<SIZE> bits;
		for (auto& c : input)
			bits[c - 'a'] = 1;

		if(bits.count()<=K)
			v.push_back(bits);
	}

	solution(0);
	cout << Max;
	return 0;
}