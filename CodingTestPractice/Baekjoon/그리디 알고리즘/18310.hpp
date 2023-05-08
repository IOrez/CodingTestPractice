#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<int> v;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		v.push_back(X);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 0)
		cout << v[N / 2 - 1];
	else
		cout << v[N / 2];

}