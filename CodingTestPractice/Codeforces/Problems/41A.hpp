#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input,matchStr;
	string revInput;
	getline(cin, input);
	getline(cin, matchStr);
	revInput.resize(input.size());
	transform(input.begin(), input.end(), revInput.rbegin(), [&](char& c1)->char {
		return c1;
	});
	bool check = (matchStr.size() == revInput.size());
	for (auto i = (size_t)0; i <= revInput.size()&&check; ++i)
		check = (matchStr[i] == revInput[i]);
	if (check)cout << "YES";
	else cout << "NO";
	return 0;
}