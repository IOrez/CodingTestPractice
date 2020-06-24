#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	string input;
	cin >> input;
	for (int i = 'a'; i <= 'z'; ++i)
	{
		int idx = input.find_first_of((char)i);
		cout << idx << " ";
	}
	return 0;
}