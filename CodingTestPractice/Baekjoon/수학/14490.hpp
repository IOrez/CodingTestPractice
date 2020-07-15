#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#pragma warning(disable:4996)
using namespace std;

string input;
stringstream ss;
int a, b, c, d;

int gcd(int n, int k)
{
	if (k == 0)return n;
	return gcd(k, n % k);
}

void solution()
{
	if (c < d)swap(c, d);
	int val = gcd(c, d);
	ss << a / val;
	ss << ":";
	ss << b / val;
	cout << ss.str();
	return;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	getline(cin, input);

	auto pos = input.find_first_of(':');
	a = c = atoi(input.substr(0, pos).c_str());
	b = d = atoi(input.substr(pos + 1).c_str());
	solution();
	return 0;
}