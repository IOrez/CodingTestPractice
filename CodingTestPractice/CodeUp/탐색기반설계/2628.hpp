#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> v(4);
	cin >> v[0] >> v[2];
	cin >> v[1] >> v[3];
	if (v[0] > v[2])swap(v[0], v[2]);
	if (v[1] > v[3])swap(v[1], v[3]);
	bool check = false;
	if (v[0] < v[1] && v[1] < v[2] && v[2] < v[3])check = true;
	if (v[1] < v[0] && v[0] < v[3] && v[3] < v[2])check = true;

	if (check)cout << "cross";
	else cout << "not cross";
	return 0;
}