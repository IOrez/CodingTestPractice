#include <iostream>
#include <iomanip>
using namespace std;
int a, b;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a >> b;
	cout << fixed<<setprecision(4) << -(float)b / a;
	return 0;
}