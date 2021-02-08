#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


using ll =long long;
using vt = vector<tuple<ll, ll, ll>>;

namespace {
	ll N, r, cx, cy,sx, sy, ex, ey;

}

int solution(vt& v) {
	int cnt = 0;
	for (auto& obj : v) {
		auto[cx, cy, r] = obj;
		int sdis = (cx - sx) * (cx - sx) + (cy - sy) * (cy - sy);
		int edis = (cx - ex) * (cx - ex) + (cy - ey) * (cy - ey);
		if ((sdis - r * r) * (edis - r * r) < 0)cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		cin >> sx >> sy >> ex >> ey;
		cin >> N;
		vt v;
		for (int i = 0; i < N; ++i) {
			cin >> cx >> cy >> r;
			v.push_back({ cx,cy,r });
		}
		
		cout << solution(v)<<'\n';

	}
	return 0;
}