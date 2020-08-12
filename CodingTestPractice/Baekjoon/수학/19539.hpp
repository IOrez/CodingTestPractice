#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N,C, d = 0, r = 0;
	cin >> N;
	vector<int> v(N);
	for (auto& i : v)
	{
		cin >> i;
		d += i / 2;
		r += i % 2;
	}
	if ((d - r) % 3 == 0 && d >= r)cout << "YES";
	else cout << "NO";
	return 0;
}