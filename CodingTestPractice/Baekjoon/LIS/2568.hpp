#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX	500001
int N;

using vpp = vector<pair<int, int>>;
using vb = vector<bool>;
using vi = vector<int>;
bool check[MAX];

int solution(vpp& connect,vpp& ans,vi& cache) {
	int idx = 0;
	ans[idx] = { 0,connect[0].first };
	cache[idx] = connect[0].second;
	for (int i = 1; i < N; ++i) {
		if (cache[idx] < connect[i].second) {
			cache[++idx] = connect[i].second;
			ans[i] = { idx,connect[i].first };
		}
		else {
			int tidx = lower_bound(cache.begin(), cache.begin()+idx, connect[i].second) - cache.begin();
			cache[tidx] = connect[i].second;
			ans[i] = { tidx,connect[i].first };
		}
	}
	return idx + 1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vpp connect(N);
	vpp ans(N);
	vi cache(N);
	for (int i = 0; i < N; ++i) {
		cin >> connect[i].first >> connect[i].second;
		check[connect[i].first] = true;
	}
	sort(connect.begin(), connect.end());

	int result = solution(connect, ans, cache);
	cout << N - result << '\n';
	int num = result - 1;
	for(int i =N-1 ;i>=0;--i)
		if (num == ans[i].first) {
			check[ans[i].second] = false;
			num--;
		}
	for (int i = 1; i < MAX; ++i)
		if (check[i])cout << i << '\n';
	
	return 0;
}