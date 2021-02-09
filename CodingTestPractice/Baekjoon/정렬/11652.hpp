#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	vector<long long> v(N);
	for(auto&i:v){
		cin >> i;
	}
	sort(v.begin(), v.end(),greater<long long>());
	long long preval = v[0];
	long long ans = preval, max_cnt = 1, cnt = 1;
	for (int i = 1; i < N; ++i) {
		if (preval != v[i])cnt = 0;
		cnt++;
		if (max_cnt <= cnt) {
			ans = v[i];
			max_cnt = cnt;
		};
		preval = v[i];
	}
	cout << ans;
	return 0;
}