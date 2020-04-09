#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	getline(cin, s);
	string out("19" + s.substr(0, 2)+"/" +s.substr(2,2)+"/"+s.substr(4,2));
	if (s[7] == '1')out.append(" M");
	else out.append(" F");
	cout << out;
	return 0;
}