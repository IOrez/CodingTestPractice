#include <iostream>
#include <string>
#include <set>
using namespace std;

constexpr int Size = 'z' - 'a' + 1;
int lower[Size];


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	set<char> cset;
	int max = -1;
	getline(cin, input);
	for (auto& c: input)
	{
		c = tolower(c);
		int val;
		val = ++lower[c - 'a'];
		if (val >= max)
		{
			if (val > max)
			{
				cset.clear();
				max = val;
			}
			cset.insert(c);
		}
	}
	if (cset.size() > 1)cout << "?";
	else cout << (char)(toupper(*cset.begin()));
	return 0;
}