#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string input,output;
void change()
{
	stringstream ss;
	for (int i = 0; i < input.size(); ++i)
		if (isupper(input[i]))
			ss << (char)tolower(input[i]);
		else if (islower(input[i]))
			ss << (char)toupper(input[i]);
	output = ss.str();
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	getline(cin, input);
	bool check = true;
	for (int i = 1; i < input.size() && check; ++i)
		check = isupper(input[i]);
	if (check)
		change();
	else
		output = input;
	cout << output;
	return 0;
}