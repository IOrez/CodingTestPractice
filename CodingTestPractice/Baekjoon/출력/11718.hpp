#include <iostream>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	int i = 0;
	while (i<100)
	{
		getline(cin, s);
		if (s.length() == 0)break;
		cout << s << '\n'; i++;
	}

	return 0;
}