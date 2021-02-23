#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;


using vll = vector<pair<long long, long long>>;

double ans;
long long sumX, sumY, vx, vy;
int T, N;
vector<int> contain;

void solution(vll& v,int idx) {
	if (contain.size() == N / 2) {
		long long tmpX = 0, tmpY = 0;
		for (auto& i : contain) {
			tmpX += v[i].first;
			tmpY += v[i].second;
		}
		
		double tmpAns = sqrt((sumX - 2 * tmpX) * (sumX - 2 * tmpX) + (sumY - 2 * tmpY) * (sumY - 2 * tmpY));
		ans = min(ans, tmpAns);
		return;
	}

	for (int i = idx; i < N; ++i) {
		contain.push_back(i);
		solution(v,i + 1);
		contain.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	while (T--) {
		ans = numeric_limits<double>::max();
		sumX = sumY = 0;
		cin >> N;
		vll v(N);
		for (auto& o : v) {
			cin >> o.first >> o.second;
			sumX += o.first;
			sumY += o.second;
		}

		solution(v, 0);
		cout <<fixed<<setprecision(12)<< ans << '\n';
	}
	
	return 0;
}