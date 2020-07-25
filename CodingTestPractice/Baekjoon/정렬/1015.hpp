#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	transform(A.begin(), A.end(), B.begin(), [&](int i)->int {return i; });
	sort(B.begin(), B.end());
	for (int i = 0; i < N; ++i)
	{
		int val = A[i];
		auto iter = find(B.begin(), B.end(), val);
		cout << iter - B.begin() << " ";
		*iter = -1;
	}
	
	return 0;
}