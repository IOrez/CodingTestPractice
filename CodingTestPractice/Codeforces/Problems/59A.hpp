#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	getline(cin, input);
	int lower_Cnt = 0, upper_Cnt = 0;
	for (auto& c : input)
		if (isupper(c))upper_Cnt++;
		else lower_Cnt++;

	if (lower_Cnt >= upper_Cnt)
		for (auto& c : input)c = tolower(c);
	else
		for (auto& c : input)c = toupper(c);

	cout << input;

	return 0;
}