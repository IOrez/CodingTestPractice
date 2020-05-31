#include <iostream>
#include <string>
//#include <regex>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string input;
	unsigned long long cnt = 0;
	getline(cin, input);
	auto spos = input.find_first_not_of(' ');
	auto epos = input.find_last_not_of(' ');
	if (spos == string::npos || epos == string::npos)cnt = -1;
	else
		for(unsigned long long i = spos; i < epos; ++i)
		if (input[i] == ' ')cnt++;
	
	/*while (regex_search(input, match,
	regex re(R"([a-z]+)",regex::icase);
	smatch match;
	int cnt = 0;
	getline(cin, input);
	while (regex_search(input, match, re )) {
		cnt++;
		input = match.suffix();
	}*/
	cout << cnt+1;
	return 0;
}