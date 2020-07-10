#include <iostream>
#include <cstdlib>
using namespace std;

#pragma warning(disable:4996)

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int year;
	cin >> year;
	bool check = false;
	year++;
	while (!check)
	{
		int temp = year;
		char buf[5];
		char* str = _itoa(temp, buf, 10);
		check = true;
		for (int i = 0; i < 3 && check; ++i)
			for (int j = i + 1; j < 4 && check; ++j)
				check = (buf[i] != buf[j]);
		
		if (check) {
			cout << buf; break;
		}
		year++;
	}
	return 0;
}