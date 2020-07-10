#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int s[10001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)cin >> s[i];
	sort(s, s + N);
	vector<int>dif(N - 1);
	for (int i = 0; i < N - 1; ++i)
		dif[i] = s[i + 1] - s[i];
	sort(dif.begin(), dif.end());
	long long sum = 0;
	for (int i = 0; i < (int)dif.size() - K + 1; ++i)
		sum += dif[i];
	cout << sum;
	return 0;
}