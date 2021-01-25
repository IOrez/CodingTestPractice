#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;


#define maxAbs 4000

int Min = numeric_limits<int>::max();
int Max = numeric_limits<int>::min();
double Sum;
int Cnt[8001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& i : v) {
		cin >> i;
		Min = min(i, Min);
		Max = max(i, Max);
		Cnt[i + maxAbs]++;
		Sum += i;
	}

	sort(v.begin(), v.end());
	int maxCnt = -1;
	bool check = false;
	int maxCntVal = 0;
	for (int i = 0; i < 8001; ++i) {
		if (maxCnt == Cnt[i]) {
			if (!check) {
				maxCntVal = i - maxAbs;
				check = true;
			}
		}
		else if (maxCnt < Cnt[i]){
			maxCnt = Cnt[i];
			maxCntVal = i - maxAbs;
			check = false;
		}
	}

	int ans = round(Sum / N);
	cout << ans <<'\n';
	cout << v[N/ 2] << '\n';
	cout << maxCntVal << '\n';
	cout << Max - Min<<'\n';

	return 0;
}