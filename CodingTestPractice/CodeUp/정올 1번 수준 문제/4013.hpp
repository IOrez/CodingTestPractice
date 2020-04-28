#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string translate(int n,int r)
{
	string s = "0123456789ABCDEF";
	string res = "";
	auto o = div(n, r);
	if (o.quot == 0)
	{
		res.push_back(s[o.rem]);
		return res;
	}
	else {
		res = translate(o.quot, r);
		res.push_back(s[o.rem]);
		return res;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	string res = translate(n, 2);
	cout << 2 << " " << translate(n, 2) << "\n";
	cout << 8 << " " << translate(n, 8) << "\n";
	cout << 16 << " " << translate(n, 16) << "\n";
	return 0;
}