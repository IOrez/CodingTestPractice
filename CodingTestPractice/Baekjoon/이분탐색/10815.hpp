#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M,Num;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)cin >> i;
	cin >> M;
	sort(v.begin(), v.end());
	for (int i = 0; i < M; ++i)
	{
		cin >> Num;
		cout << (int)binary_search(v.begin(), v.end(), Num) << " ";
	}
}