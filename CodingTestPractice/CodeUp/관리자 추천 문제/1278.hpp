#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	getline(cin, input);
	cout << input.length();
	return 0;
}