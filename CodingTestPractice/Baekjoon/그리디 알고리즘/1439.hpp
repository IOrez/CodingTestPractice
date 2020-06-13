#include <iostream>
#include <string>
using namespace std;

int group[2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string input;
	int i;
	cin >> input;
	for (i = 0; i < input.size() - 1; ++i)
		if (input[i] != input[i + 1])group[input[i] - '0']++;
	group[input[i] - '0']++;
	cout << (group[0] < group[1] ? group[0] : group[1]);


	return 0;
}