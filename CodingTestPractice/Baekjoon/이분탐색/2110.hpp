#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, C, X;


int Search(vector<int>& v, int left, int right) {
	int count = 1, maxLength = 0;
	while (left < right && count != C) {
		int mid = (left + right) / 2;
		if (v[mid] - v[left] - 1 > v[right] - v[mid] - 1) {
			maxLength = max(maxLength,v[mid] - v[left] - 1);
			right = mid;
		}
		else {
			maxLength = max(maxLength,v[right] - v[mid] - 1);
			left = mid;
		}
		count++;
	}
	return (C != count) ? -1 : maxLength;
}

int Solution(vector<int>& v) {
	int ans = -1;
	
	ans = Search(v, 0, N - 1);

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