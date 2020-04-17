#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string input;
	string word("hello");
	cin >> input;

	bool check = true;
	auto pos = input.find_first_of('h');
	if (pos == string::npos)check = false;
	pos = input.find_first_of('e', pos+1);
	if (pos == string::npos)check = false;
	pos = input.find_first_of('l', pos+1);
	if (pos == string::npos)check = false;
	pos = input.find_first_of('l', pos+1);
	if (pos == string::npos)check = false;
	pos = input.find_first_of('o', pos+1);
	if (pos == string::npos)check = false;

	if (check)cout << "YES";
	else cout << "NO";
	return 0;
}