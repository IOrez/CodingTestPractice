#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, C, X;


bool Check(vector<int>& v,int length,int& count) {
	int idx = 0;
	for (int i = 0; i < N&&count<=C; ++i) {
		if (v[idx] + length <= v[i]) {
			count++;
			idx = i;
		}
	}
	return (count >= C);
}

int Solution(vector<int>& v) {
	int left = 0, right = v[N - 1];
	int ans = -1;
	while (left <= right) {
		int count = 1, mid = 0;
		mid = (left + right) / 2;
		if (Check(v, mid,count))
			ans = max(ans, mid);
		if (count < C)right = mid - 1;
		else left = mid + 1;
	}
	return ans;
}


int main() {
	cin >> N >> C;
	vector<int> v;
	for (int i = 0; i < N; ++i) {
		cin >> X;
		v.push_back(X);
	}
	sort(v.begin(), v.end());
	cout << Solution(v);
	return 0;
}