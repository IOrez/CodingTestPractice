#include<iostream>
#include <vector>
using namespace std;

int Arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)cin >> Arr[i];
	for (int i = n - 1; i >= 0; --i)
		v.insert(v.begin() + Arr[i], i+1);

	for (auto i : v)
		if (i != 0)cout << i << " ";
	return 0;
}