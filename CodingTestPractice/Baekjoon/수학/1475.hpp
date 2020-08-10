#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int cnt[10];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	getline(cin, input);
	for (auto c : input)
		cnt[c - '0']++;
	
	int set = 0, val = ceil((float)(cnt[6] + cnt[9]) / 2);
	for (int i = 0; i < 10; ++i)
		if (i == 6 || i == 9)continue;
		else if (set < cnt[i])set = cnt[i];
	set = set < val ? val : set;
	cout << set;
	return 0;
}