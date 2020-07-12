#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (auto& i : A)cin >> i;
	for (auto& i : B)cin >> i;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(),greater<int>());
	int sum = 0;
	for (int i = 0; i < N; ++i)
		sum += A[i] * B[i];
	cout << sum;
	return 0;
}