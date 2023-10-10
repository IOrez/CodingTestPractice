#include <iostream>
#include <string>
#include <memory.h>
#include <cstring>
using namespace std;

#define MAX_SIZE 1000001
int nFail[MAX_SIZE];

void MakeFailFunc(string str)
{
	memset(nFail, 0, sizeof(int) * MAX_SIZE);
	int n = str.size();
	for (int i = 1, j = 0; i < n; i++)
	{
		while (j > 0 && str[i] != str[j])
			j = nFail[j - 1];

		if (str[i] == str[j])
			j++;

		nFail[i] = j;
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string str;
	do
	{
		getline(cin, str);
		if (str == ".")
			break;

		MakeFailFunc(str);
		int n = str.size();

		int nRepeatTermLen = n - nFail[n - 1];
		if (n % nRepeatTermLen != 0)
			cout << 1 << '\n';
		else
			cout << n/nRepeatTermLen << '\n';

	} while (true);
	return 0;
}