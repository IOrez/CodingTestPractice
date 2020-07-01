#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	cin >> input;
	sort(input.begin(), input.end(), [](char a, char b)->bool {
		return a >= b;
	});
	cout << input;
	return 0;
}